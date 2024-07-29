; ModuleID = 'spirit lang jit'
source_filename = "spirit lang jit"

define void @global_main_init() {
entry_global_main_init:
  ret void
}

declare i64 @printf(ptr, ...)

declare ptr @memcpy(ptr, ptr, i64)

define ptr @getPtr_i_iP_iA-1_iA-1A1_iA-1A1A2(i64 %a, ptr %p, ptr %arr1, ptr %arr2, ptr %arr3) {
entry_getPtr:
  %0 = alloca i64, align 8
  store i64 %a, ptr %0, align 4
  %1 = alloca ptr, align 8
  store ptr %p, ptr %1, align 8
  %2 = alloca ptr, align 8
  store ptr %arr1, ptr %2, align 8
  %3 = alloca ptr, align 8
  store ptr %arr2, ptr %3, align 8
  %4 = alloca ptr, align 8
  store ptr %arr3, ptr %4, align 8
  %5 = load ptr, ptr %1, align 8
  %6 = load i64, ptr %5, align 4
  store i64 %6, ptr %0, align 4
  %7 = getelementptr inbounds [18446744073709551615 x i64], ptr %2, i32 0, i32 0
  %8 = load i64, ptr %7, align 4
  store i64 %8, ptr %0, align 4
  %9 = getelementptr inbounds [18446744073709551615 x i64], ptr %2, i32 0, i64 0
  %10 = load i64, ptr %9, align 4
  store i64 %10, ptr %0, align 4
  %11 = getelementptr inbounds [18446744073709551615 x [1 x i64]], ptr %3, i32 0, i32 0
  %12 = getelementptr inbounds [1 x i64], ptr %11, i32 0, i32 0
  %13 = load i64, ptr %12, align 4
  store i64 %13, ptr %0, align 4
  %14 = getelementptr inbounds [18446744073709551615 x [1 x i64]], ptr %3, i32 0, i64 0
  %15 = getelementptr inbounds [1 x i64], ptr %14, i32 0, i64 1
  %16 = load i64, ptr %15, align 4
  store i64 %16, ptr %0, align 4
  %17 = getelementptr inbounds [18446744073709551615 x [1 x [2 x i64]]], ptr %4, i32 0, i32 0
  %18 = getelementptr inbounds [1 x [2 x i64]], ptr %17, i32 0, i32 0
  %19 = getelementptr inbounds [2 x i64], ptr %18, i32 0, i32 0
  %20 = load i64, ptr %19, align 4
  store i64 %20, ptr %0, align 4
  %21 = getelementptr inbounds [18446744073709551615 x [1 x [2 x i64]]], ptr %4, i32 0, i64 0
  %22 = getelementptr inbounds [1 x [2 x i64]], ptr %21, i32 0, i64 1
  %23 = getelementptr inbounds [2 x i64], ptr %22, i32 0, i64 2
  %24 = load i64, ptr %23, align 4
  store i64 %24, ptr %0, align 4
  ret ptr null
}

define void @ff_i(i64 %a) {
entry_ff:
  %0 = alloca i64, align 8
  store i64 %a, ptr %0, align 4
  %1 = load i64, ptr %0, align 4
  %2 = add i64 %1, 1
  store i64 %2, ptr %0, align 4
  ret void
}

define i64 @main() {
entry_main:
  call void @global_main_init()
  ret i64 0
}
