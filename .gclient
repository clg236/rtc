solutions = [
  { "name"        : "src",
    "url"         : "https://chromium.googlesource.com/external/webrtc.git",
    "deps_file"   : "DEPS",
    "managed"     : True,
    "custom_deps" : {
    },
    "custom_vars": {},
  },
]
cache_dir = None
target_os = ["android", "unix"]
