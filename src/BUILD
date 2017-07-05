cc_binary(
  name = "main",
  srcs = ["RunSystem.cpp"],
  deps = ["//src/lib:libs"]
)

cc_library(
  name = "libs",
  srcs = glob(["*.cpp"]),
  hdrs = glob(["*.hpp"])
)
