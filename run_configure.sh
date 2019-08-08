#export CC="/home/admin/opt/cross/bin/i686-elf-gcc"
#export CXX="/home/admin/opt/cross/bin/i686-elf-g++"
#export LD="/home/admin/opt/cross/bin/i686-elf-ld"

# -B /home/admin/Github/mkeykernel/obj/libc/
ldlibs= #"-L /home/admin/Github/mkeykernel/obj/libc/"

export CFLAGS="-m32 -g -fno-stack-protector $ldlibs"
export CXXFLAGS="-m32 -g -fno-stack-protector $ldlibs"
export LDFLAGS="-m32 -g $ldlibs"

export LIBS="-lgcc"

# Note: to rebuild configure file, you must run autogen.sh

./configure --build=i686-pc-x86-corax --disable-pulseaudio --disable-alsa --disable-oss --disable-video-x11 --disable-video-opengl --disable-input-tslib --disable-sdl-dlopen --disable-pthreads --enable-timers --prefix=$(pwd)/build2