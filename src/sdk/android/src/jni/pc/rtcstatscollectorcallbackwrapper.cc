/*
 *  Copyright 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#include "sdk/android/src/jni/pc/rtcstatscollectorcallbackwrapper.h"

#include <string>
#include <vector>

#include "rtc_base/stringencode.h"
#include "sdk/android/generated_external_classes_jni/jni/BigInteger_jni.h"
#include "sdk/android/generated_peerconnection_jni/jni/RTCStatsCollectorCallback_jni.h"
#include "sdk/android/generated_peerconnection_jni/jni/RTCStatsReport_jni.h"
#include "sdk/android/generated_peerconnection_jni/jni/RTCStats_jni.h"

namespace webrtc {
namespace jni {

namespace {

jobject NativeToJavaBigInteger(JNIEnv* env, uint64_t u) {
  return JNI_BigInteger::Java_BigInteger_ConstructorJMBI_JLS(
      env, NativeToJavaString(env, rtc::ToString(u)));
}

jobjectArray NativeToJavaBigIntegerArray(
    JNIEnv* env,
    const std::vector<uint64_t>& container) {
  return NativeToJavaObjectArray(
      env, container, java_math_BigInteger_clazz(env), &NativeToJavaBigInteger);
}

jobject MemberToJava(JNIEnv* env, const RTCStatsMemberInterface& member) {
  switch (member.type()) {
    case RTCStatsMemberInterface::kBool:
      return NativeToJavaBoolean(env, *member.cast_to<RTCStatsMember<bool>>());

    case RTCStatsMemberInterface::kInt32:
      return NativeToJavaInteger(env,
                                 *member.cast_to<RTCStatsMember<int32_t>>());

    case RTCStatsMemberInterface::kUint32:
      return NativeToJavaLong(env, *member.cast_to<RTCStatsMember<uint32_t>>());

    case RTCStatsMemberInterface::kInt64:
      return NativeToJavaLong(env, *member.cast_to<RTCStatsMember<int64_t>>());

    case RTCStatsMemberInterface::kUint64:
      return NativeToJavaBigInteger(
          env, *member.cast_to<RTCStatsMember<uint64_t>>());

    case RTCStatsMemberInterface::kDouble:
      return NativeToJavaDouble(env, *member.cast_to<RTCStatsMember<double>>());

    case RTCStatsMemberInterface::kString:
      return NativeToJavaString(env,
                                *member.cast_to<RTCStatsMember<std::string>>());

    case RTCStatsMemberInterface::kSequenceBool:
      return NativeToJavaBooleanArray(
          env, *member.cast_to<RTCStatsMember<std::vector<bool>>>());

    case RTCStatsMemberInterface::kSequenceInt32:
      return NativeToJavaIntegerArray(
          env, *member.cast_to<RTCStatsMember<std::vector<int32_t>>>());

    case RTCStatsMemberInterface::kSequenceUint32: {
      const std::vector<uint32_t>& v =
          *member.cast_to<RTCStatsMember<std::vector<uint32_t>>>();
      return NativeToJavaLongArray(env,
                                   std::vector<int64_t>(v.begin(), v.end()));
    }
    case RTCStatsMemberInterface::kSequenceInt64:
      return NativeToJavaLongArray(
          env, *member.cast_to<RTCStatsMember<std::vector<int64_t>>>());

    case RTCStatsMemberInterface::kSequenceUint64:
      return NativeToJavaBigIntegerArray(
          env, *member.cast_to<RTCStatsMember<std::vector<uint64_t>>>());

    case RTCStatsMemberInterface::kSequenceDouble:
      return NativeToJavaDoubleArray(
          env, *member.cast_to<RTCStatsMember<std::vector<double>>>());

    case RTCStatsMemberInterface::kSequenceString:
      return NativeToJavaStringArray(
          env, *member.cast_to<RTCStatsMember<std::vector<std::string>>>());
  }
  RTC_NOTREACHED();
  return nullptr;
}

jobject NativeToJavaRtcStats(JNIEnv* env, const RTCStats& stats) {
  JavaMapBuilder builder(env);
  for (const auto& member : stats.Members()) {
    if (!member->is_defined())
      continue;
    ScopedLocalRefFrame local_ref_frame(env);
    builder.put(NativeToJavaString(env, member->name()),
                MemberToJava(env, *member));
  }
  return Java_RTCStats_create(
      env, stats.timestamp_us(), NativeToJavaString(env, stats.type()),
      NativeToJavaString(env, stats.id()), builder.GetJavaMap());
}

jobject NativeToJavaRtcStatsReport(
    JNIEnv* env,
    const rtc::scoped_refptr<const RTCStatsReport>& report) {
  jobject j_stats_map =
      NativeToJavaMap(env, *report, [](JNIEnv* env, const RTCStats& stats) {
        return std::make_pair(NativeToJavaString(env, stats.id()),
                              NativeToJavaRtcStats(env, stats));
      });
  return Java_RTCStatsReport_create(env, report->timestamp_us(), j_stats_map);
}

}  // namespace

RTCStatsCollectorCallbackWrapper::RTCStatsCollectorCallbackWrapper(
    JNIEnv* jni,
    jobject j_callback)
    : j_callback_global_(jni, j_callback) {}

void RTCStatsCollectorCallbackWrapper::OnStatsDelivered(
    const rtc::scoped_refptr<const RTCStatsReport>& report) {
  JNIEnv* jni = AttachCurrentThreadIfNeeded();
  ScopedLocalRefFrame local_ref_frame(jni);
  jobject j_report = NativeToJavaRtcStatsReport(jni, report);
  Java_RTCStatsCollectorCallback_onStatsDelivered(jni, *j_callback_global_,
                                                  j_report);
}

}  // namespace jni
}  // namespace webrtc
