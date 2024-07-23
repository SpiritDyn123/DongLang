; ModuleID = 'spirit lang jit'
source_filename = "spirit lang jit"

@0 = private unnamed_addr constant [18 x i8] c"hello world a:%d\0A\00", align 1

define void @global_main_init() {
entry_global_main_init:
  ret void
  ret void
}

declare i64 @printf(ptr, ...)

declare ptr @memcpy(ptr, ptr, i64)

define i64 @getV1() {
entry_getV1:
  ret i64 1
}

define i64 @getInt() {
entry_getInt:
  ret i64 0
}

define void @getVoid() {
entry_getVoid:
  ret void
}

define ptr @getPtr() {
entry_getPtr:
  ret ptr null
}

define [1 x i64] @getArr_iP_iA1_iA1A2(ptr %p, ptr %arr, ptr %aarr1) {
entry_getArr:
  ret [1 x i64] zeroinitializer
}

define i64 @main() {
entry_main:
  call void @global_main_init()
  %a = alloca i64, align 8
  store i64 0, ptr %a, align 4
  %b = alloca i64, align 8
  store i64 0, ptr %b, align 4
  %pa = alloca ptr, align 8
  store ptr null, ptr %pa, align 8
  %pb = alloca ptr, align 8
  store ptr null, ptr %pb, align 8
  %ppa = alloca ptr, align 8
  store ptr null, ptr %ppa, align 8
  %ppb = alloca ptr, align 8
  store ptr null, ptr %ppb, align 8
  %arr1 = alloca [1 x i64], align 8
  store [1 x i64] zeroinitializer, ptr %arr1, align 4
  %arr2 = alloca [2 x [2 x i64]], align 8
  store [2 x [2 x i64]] zeroinitializer, ptr %arr2, align 4
  %0 = getelementptr inbounds [1 x i64], ptr %arr1, i32 0, i32 0
  store ptr %0, ptr %pa, align 8
  %1 = load ptr, ptr %ppa, align 8
  %2 = load ptr, ptr %1, align 8
  %3 = load i64, ptr %2, align 4
  store i64 %3, ptr %a, align 4
  %4 = load ptr, ptr %ppa, align 8
  %5 = getelementptr inbounds ptr, ptr %4, i64 1
  %6 = load ptr, ptr %5, align 8
  %7 = getelementptr inbounds i64, ptr %6, i64 1
  %8 = load i64, ptr %7, align 4
  store i64 %8, ptr %a, align 4
  %9 = getelementptr inbounds [2 x [2 x i64]], ptr %arr2, i32 0, i64 1
  %10 = getelementptr inbounds [2 x i64], ptr %9, i32 0, i64 1
  %11 = load i64, ptr %10, align 4
  store i64 %11, ptr %a, align 4
  %12 = getelementptr inbounds [1 x i64], ptr %arr1, i32 0, i32 0
  %13 = load ptr, ptr %pa, align 8
  %14 = call [1 x i64] @getArr_iP_iA1_iA1A2(ptr %12, ptr %13, ptr %arr2)
  %15 = load ptr, ptr %ppa, align 8
  %16 = load ptr, ptr %15, align 8
  %17 = load i64, ptr %16, align 4
  %18 = call i64 (ptr, ...) @printf(ptr @0, i64 %17)
  ret i64 0
}
