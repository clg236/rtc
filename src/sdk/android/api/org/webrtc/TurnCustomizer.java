/*
 *  Copyright 2017 The WebRTC project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

package org.webrtc;

/** Java wrapper for a C++ TurnCustomizer. */
public class TurnCustomizer {
  final long nativeTurnCustomizer;

  public TurnCustomizer(long nativeTurnCustomizer) {
    this.nativeTurnCustomizer = nativeTurnCustomizer;
  }

  public void dispose() {
    freeNativeTurnCustomizer(nativeTurnCustomizer);
  }

  private static native void freeNativeTurnCustomizer(long nativeTurnCustomizer);

  @CalledByNative
  long getNativeTurnCustomizer() {
    return nativeTurnCustomizer;
  }
}
