; ModuleID = 'spirit lang jit'
source_filename = "spirit lang jit"

@ga = dso_local global i64 1

define void @global_main_init() {
entry_global_main_init:
  ret void
}

declare i64 @printf(ptr, ...)

declare ptr @memcpy(ptr, ptr, i64)

define i64 @getga() {
entry_getga:
  %0 = load i64, ptr @ga, align 4
  %1 = add i64 %0, 1
  store i64 %1, ptr @ga, align 4
  %2 = load i64, ptr @ga, align 4
  ret i64 %2
}

define i64 @ff_i_i_i_i(i64 %0, i64 %1, i64 %2, i64 %3) {
entry_ff:
  %a = alloca i64, align 8
  store i64 %0, ptr %a, align 4
  %b = alloca i64, align 8
  store i64 %1, ptr %b, align 4
  %c = alloca i64, align 8
  store i64 %2, ptr %c, align 4
  %d = alloca i64, align 8
  store i64 %3, ptr %d, align 4
  ret i64 0
}

define i64 @main() {
entry_main:
  call void @global_main_init()
  %a = alloca i64, align 8
  store i64 0, ptr %a, align 4
  %0 = load i64, ptr %a, align 4
  %1 = load i64, ptr @ga, align 4
  %2 = call i64 @getga()
  %3 = call i64 @ff_i_i_i_i(i64 %0, i64 5, i64 %1, i64 %2)
  %4 = load i64, ptr @ga, align 4
  %5 = call i64 @getga()
  %6 = call i64 @ff_i_i_i_i(i64 1, i64 2, i64 %4, i64 %5)
  %7 = call i64 @getga()
  %8 = call i64 @ff_i_i_i_i(i64 1, i64 2, i64 3, i64 %7)
  %9 = call i64 @ff_i_i_i_i(i64 1, i64 2, i64 3, i64 4)
  ret i64 0
}
