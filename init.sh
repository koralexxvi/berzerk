set -e
if [ -d "./build" ]; then
	meson setup --reconfigure build
else
	meson setup build
fi
if [ ! -L ./build/res ]; then
	ln -rs ./res ./build/res
fi
