; ModuleID = 'spirit lang jit'
source_filename = "spirit lang jit"

@0 = private unnamed_addr constant [15 x i8] c"sum:%d  pp:%d\0A\00", align 1

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

define [5 x i64] @getArr_i_iP_iA5(i64 %a, ptr %p, ptr %arr) {
entry_getArr:
  ret [5 x i64] zeroinitializer
}

define i64 @main() {
entry_main:
  call void @global_main_init()
  %p = alloca ptr, align 8
  store ptr null, ptr %p, align 8
  %pp = alloca ptr, align 8
  store ptr null, ptr %pp, align 8
  %a = alloca i64, align 8
  store i64 5, ptr %a, align 4
  store ptr %a, ptr %p, align 8
  store ptr %p, ptr %pp, align 8
  %sum = alloca i64, align 8
  store i64 0, ptr %sum, align 4
  %i = alloca i64, align 8
  store i64 1, ptr %i, align 4
  br label %0

0:                                                ; preds = %entry_main, %7
  %1 = load i64, ptr %i, align 4
  %2 = icmp slt i64 %1, 100
  br i1 %2, label %3, label %10

3:                                                ; preds = %0
  %4 = load i64, ptr %sum, align 4
  %5 = load i64, ptr %i, align 4
  %6 = add i64 %4, %5
  store i64 %6, ptr %sum, align 4
  br label %7

7:                                                ; preds = %3
  %8 = load i64, ptr %i, align 4
  %9 = add i64 %8, 1
  store i64 %9, ptr %i, align 4
  br label %0

10:                                               ; preds = %0
  %11 = load i64, ptr %a, align 4
  %12 = add i64 %11, 1
  store i64 %12, ptr %a, align 4
  %13 = load i64, ptr %sum, align 4
  %14 = load ptr, ptr %pp, align 8
  %15 = load ptr, ptr %14, align 8
  %16 = load i64, ptr %15, align 4
  %17 = call i64 (ptr, ...) @printf(ptr @0, i64 %13, i64 %16)
  ret i64 0
}
