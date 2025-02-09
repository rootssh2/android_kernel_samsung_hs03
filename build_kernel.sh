#!/bin/bash

if [ ! -d $(pwd)/toolchain/clang/host/linux-x86/clang-r416183b ]; then
	mkdir -p $(pwd)/toolchain/clang/host/linux-x86/clang-r416183b
	curl -sL https://android.googlesource.com/platform/prebuilts/clang/host/linux-x86/+archive/refs/tags/android-14.0.0_r0.68/clang-r416183b.tar.gz | tar -xzf - --directory $(pwd)/toolchain/clang/host/linux-x86/clang-r416183b
fi

export PATH="$(pwd)/toolchain/clang/host/linux-x86/clang-r416183b/bin:$PATH"
export ARCH=arm64


export KCFLAGS=-w
export CONFIG_SECTION_MISMATCH_WARN_ONLY=y

make -C $(pwd) O=$(pwd)/out KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y a03s_defconfig
make -C $(pwd) O=$(pwd)/out CROSS_COMPILE=aarch64-linux-gnu- CC=clang AR=llvm-ar NM=llvm-nm OBJCOPY=llvm-objcopy OBJDUMP=llvm-objdump STRIP=llvm-strip LLVM_IAS=1 KCFLAGS=-w CONFIG_SECTION_MISMATCH_WARN_ONLY=y -j16
cp out/arch/arm64/boot/Image $(pwd)/arch/arm64/boot/Image
