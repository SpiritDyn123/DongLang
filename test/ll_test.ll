; ModuleID = 'll_test.cpp'
source_filename = "ll_test.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define dso_local noundef i32 @_Z3fffiPiS_PA4_i(i32 noundef %0, ptr noundef %1, ptr noundef %2, ptr noundef %3) #0 {
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca ptr, align 8
  %8 = alloca ptr, align 8
  %9 = alloca ptr, align 8
  store i32 %0, ptr %6, align 4
  store ptr %1, ptr %7, align 8
  store ptr %2, ptr %8, align 8
  store ptr %3, ptr %9, align 8
  %10 = load i32, ptr %6, align 4
  %11 = icmp sgt i32 %10, 1
  br i1 %11, label %12, label %13

12:                                               ; preds = %4
  store i32 5, ptr %5, align 4
  br label %14

13:                                               ; preds = %4
  store i32 1, ptr %5, align 4
  br label %14

14:                                               ; preds = %13, %12
  %15 = load i32, ptr %5, align 4
  ret i32 %15
}

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define dso_local noundef i32 @_Z4getVv() #0 {
  call void @llvm.trap()
  unreachable
}

; Function Attrs: cold noreturn nounwind
declare void @llvm.trap() #1

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define dso_local noundef ptr @_Z7getPtr1v() #0 {
  call void @llvm.trap()
  unreachable
}

; Function Attrs: mustprogress noinline nounwind optnone uwtable
define dso_local noundef ptr @_Z7getPtr2v() #0 {
  call void @llvm.trap()
  unreachable
}

; Function Attrs: mustprogress noinline norecurse nounwind optnone uwtable
define dso_local noundef i32 @main() #2 {
  %1 = alloca i32, align 4
  %2 = alloca ptr, align 8
  %3 = alloca ptr, align 8
  %4 = alloca [3 x i32], align 4
  %5 = alloca [3 x [4 x i32]], align 16
  %6 = alloca ptr, align 8
  %7 = alloca [5 x ptr], align 16
  %8 = getelementptr inbounds [5 x ptr], ptr %7, i64 0, i64 0
  %9 = load ptr, ptr %8, align 16
  %10 = load i32, ptr %9, align 4
  store i32 %10, ptr %1, align 4
  %11 = getelementptr inbounds [5 x ptr], ptr %7, i64 0, i64 1
  %12 = load ptr, ptr %11, align 8
  %13 = getelementptr inbounds i32, ptr %12, i64 2
  %14 = load i32, ptr %13, align 4
  store i32 %14, ptr %1, align 4
  %15 = getelementptr inbounds [5 x ptr], ptr %7, i64 0, i64 1
  %16 = load ptr, ptr %15, align 8
  %17 = load i32, ptr %16, align 4
  store i32 %17, ptr %1, align 4
  %18 = getelementptr inbounds [5 x ptr], ptr %7, i64 0, i64 0
  %19 = load ptr, ptr %18, align 16
  %20 = getelementptr inbounds i32, ptr %19, i64 1
  %21 = load i32, ptr %20, align 4
  store i32 %21, ptr %1, align 4
  %22 = load i32, ptr %1, align 4
  %23 = getelementptr inbounds [5 x ptr], ptr %7, i64 0, i64 1
  %24 = load ptr, ptr %23, align 8
  store i32 %22, ptr %24, align 4
  %25 = load i32, ptr %1, align 4
  %26 = getelementptr inbounds [5 x ptr], ptr %7, i64 0, i64 0
  %27 = load ptr, ptr %26, align 16
  %28 = getelementptr inbounds i32, ptr %27, i64 1
  store i32 %25, ptr %28, align 4
  ret i32 0
}

attributes #0 = { mustprogress noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { cold noreturn nounwind }
attributes #2 = { mustprogress noinline norecurse nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.6 (https://github.com/llvm/llvm-project 6009708b4367171ccdbf4b5905cb6a803753fe18)"}
