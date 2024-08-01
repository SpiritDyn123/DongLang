; ModuleID = 'spirit lang jit'
source_filename = "spirit lang jit"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

define void @global_main_init() {
entry_global_main_init:
  ret void
}

declare i64 @printf(ptr, ...)

declare ptr @memcpy(ptr, ptr, i64)

define void @fff_iP_iA4P(ptr %0, ptr %1) {
entry_fff:
  %arr1 = alloca ptr, align 8
  store ptr %0, ptr %arr1, align 8
  %arr2 = alloca ptr, align 8
  store ptr %1, ptr %arr2, align 8
  ret void
}

define i64 @getV() {
entry_getV:
  ret i64 0
}

define ptr @getPtr1() {
entry_getPtr1:
  ret ptr null
}

define ptr @getPtr2() {
entry_getPtr2:
  ret ptr null
}

define i64 @main() {
entry_main:
  call void @global_main_init()
  %a = alloca i64, align 8
  store i64 0, ptr %a, align 4
  %p = alloca ptr, align 8
  store ptr null, ptr %p, align 8
  %pp = alloca ptr, align 8
  store ptr null, ptr %pp, align 8
  %arr1 = alloca [3 x i64], align 8
  store [3 x i64] zeroinitializer, ptr %arr1, align 4
  %arr = alloca [3 x [4 x i64]], align 8
  store [3 x [4 x i64]] zeroinitializer, ptr %arr, align 4
  %0 = call ptr @getPtr2()
  %1 = getelementptr inbounds i64, ptr %0, i64 2
  %2 = load i64, ptr %1, align 4
  store i64 %2, ptr %a, align 4
  %3 = load i64, ptr %a, align 4
  %4 = call i64 (ptr, ...) @printf(ptr @0, i64 %3)
  ret i64 0
}
