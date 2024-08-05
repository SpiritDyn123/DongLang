; ModuleID = 'spirit lang jit'
source_filename = "spirit lang jit"

@0 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
@1 = private unnamed_addr constant [12 x i8] c"a:%d <= 10\0A\00", align 1

define void @global_main_init() {
entry_global_main_init:
  ret void
}

declare i64 @printf(ptr, ...)

declare ptr @memcpy(ptr, ptr, i64)

define void @fff_i_iP_iP_iA4P(i64 %0, ptr %1, ptr %2, ptr %3) {
entry_fff:
  %a = alloca i64, align 8
  store i64 %0, ptr %a, align 4
  %p = alloca ptr, align 8
  store ptr %1, ptr %p, align 8
  %arr1 = alloca ptr, align 8
  store ptr %2, ptr %arr1, align 8
  %arr2 = alloca ptr, align 8
  store ptr %3, ptr %arr2, align 8
  %4 = load ptr, ptr %arr2, align 8
  %5 = icmp eq ptr %4, null
  br i1 %5, label %6, label %7

6:                                                ; preds = %entry_fff
  ret void
  br label %7

7:                                                ; preds = %6, %entry_fff
  %8 = load ptr, ptr %arr2, align 8
  %9 = getelementptr inbounds [4 x i64], ptr %8, i64 1
  %10 = getelementptr inbounds [4 x i64], ptr %9, i32 0, i64 2
  store i64 102, ptr %10, align 4
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
  %arr1 = alloca [5 x i64], align 8
  store [5 x i64] zeroinitializer, ptr %arr1, align 4
  %arr2 = alloca [3 x [4 x i64]], align 8
  store [3 x [4 x i64]] zeroinitializer, ptr %arr2, align 4
  %parr = alloca ptr, align 8
  store ptr null, ptr %parr, align 8
  %parr2 = alloca [5 x ptr], align 8
  store [5 x ptr] zeroinitializer, ptr %parr2, align 8
  store i64 100, ptr %a, align 4
  %0 = load i64, ptr %a, align 4
  %1 = icmp ne i64 %0, 0
  br i1 %1, label %2, label %3

2:                                                ; preds = %entry_main
  br label %3

3:                                                ; preds = %2, %entry_main
  %a1 = alloca i64, align 8
  store i64 2221, ptr %a1, align 4
  %4 = load i64, ptr %a1, align 4
  %5 = icmp sgt i64 %4, 10
  br i1 %5, label %6, label %14

6:                                                ; preds = %3
  %7 = load i64, ptr %a1, align 4
  %8 = load ptr, ptr %p, align 8
  %9 = getelementptr inbounds [5 x i64], ptr %arr1, i32 0, i32 0
  call void @fff_i_iP_iP_iA4P(i64 %7, ptr %8, ptr %9, ptr null)
  %10 = getelementptr inbounds [3 x [4 x i64]], ptr %arr2, i32 0, i64 1
  %11 = getelementptr inbounds [4 x i64], ptr %10, i32 0, i64 2
  %12 = load i64, ptr %11, align 4
  %13 = call i64 (ptr, ...) @printf(ptr @0, i64 %12)
  br label %17

14:                                               ; preds = %3
  %15 = load i64, ptr %a1, align 4
  %16 = call i64 (ptr, ...) @printf(ptr @1, i64 %15)
  br label %17

17:                                               ; preds = %14, %6
  ret i64 0
}
