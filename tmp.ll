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

define i64 @fff_i_iP_iP_iA4P(i64 %0, ptr %1, ptr %2, ptr %3) {
entry_fff:
  %a = alloca i64, align 8
  store i64 %0, ptr %a, align 4
  %p = alloca ptr, align 8
  store ptr %1, ptr %p, align 8
  %arr1 = alloca ptr, align 8
  store ptr %2, ptr %arr1, align 8
  %arr2 = alloca ptr, align 8
  store ptr %3, ptr %arr2, align 8
  %4 = alloca i64, align 8
  %5 = load ptr, ptr %arr2, align 8
  %6 = icmp ne ptr %5, null
  %7 = xor i1 %6, true
  br i1 %7, label %8, label %9

8:                                                ; preds = %entry_fff
  store i64 -1, ptr %4, align 4
  br label %14

9:                                                ; preds = %entry_fff
  %10 = load ptr, ptr %arr2, align 8
  %11 = getelementptr inbounds [4 x i64], ptr %10, i64 1
  %12 = getelementptr inbounds [4 x i64], ptr %11, i32 0, i64 2
  store i64 100, ptr %12, align 4
  %13 = load i64, ptr %a, align 4
  store i64 %13, ptr %4, align 4
  br label %14

14:                                               ; preds = %9, %8
  %15 = load i64, ptr %4, align 4
  ret i64 %15
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
  %0 = alloca i64, align 8
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
  %1 = load i64, ptr %a, align 4
  %2 = icmp ne i64 %1, 0
  br i1 %2, label %3, label %4

3:                                                ; preds = %entry_main
  br label %4

4:                                                ; preds = %3, %entry_main
  %a1 = alloca i64, align 8
  store i64 2221, ptr %a1, align 4
  %5 = load i64, ptr %a1, align 4
  %6 = icmp sgt i64 %5, 10
  br i1 %6, label %7, label %17

7:                                                ; preds = %4
  %8 = load i64, ptr %a1, align 4
  %9 = load ptr, ptr %p, align 8
  %10 = getelementptr inbounds [5 x i64], ptr %arr1, i32 0, i32 0
  %11 = getelementptr inbounds [3 x [4 x i64]], ptr %arr2, i32 0, i32 0
  %12 = call i64 @fff_i_iP_iP_iA4P(i64 %8, ptr %9, ptr %10, ptr %11)
  %arr3 = alloca [3 x [4 x i64]], align 8
  store [3 x [4 x i64]] zeroinitializer, ptr %arr3, align 4
  %13 = getelementptr inbounds [3 x [4 x i64]], ptr %arr3, i32 0, i64 1
  %14 = getelementptr inbounds [4 x i64], ptr %13, i32 0, i64 2
  %15 = load i64, ptr %14, align 4
  %16 = call i64 (ptr, ...) @printf(ptr @0, i64 %15)
  br label %20

17:                                               ; preds = %4
  %18 = load i64, ptr %a1, align 4
  %19 = call i64 (ptr, ...) @printf(ptr @1, i64 %18)
  br label %20

20:                                               ; preds = %17, %7
  %21 = load i64, ptr %0, align 4
  ret i64 %21
}
