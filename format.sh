for f in $(find src -type f -name '*.cpp'); do
	clang-format -i $f &
done
for f in $(find include -type f -name '*.hpp'); do
	clang-format -i $f &
done
wait
