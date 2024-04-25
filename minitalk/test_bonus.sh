#!/bin/bash
alphabets="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
numbers="0123456789"
korean="가나다라마바사아자차카타파하가나다라마바사아자차카타파하가나다라마바사아자차카타파하"
emoji="🥺🥺🥺🥺🥺🥺😀😎😤😎🧐🤣😇🥺😀😎😤😎🧐🥺🥺🥺🥺🥺🥺😀😎😤😎🧐🤣😇🥺😀😎😤😎🧐🥺🥺🥺🥺🥺🥺😀😎😤😎🧐🤣😇🥺😀😎😤😎🧐"
test_str="This is test string 0. This is test string 1.\
This is test string 2. This is test string 3. This is test string 4.\
This is test string 5. This is test string 6. This is test string 7.\
This is test string 8. This is test string 9. This is test string 10.\
This is test string 11. This is test string 12. This is test string 13.\
This is test string 14. This is test string 15. This is test string 16.\
This is test string 17. This is test string 18. This is test string 19."

echo "Test Minitalk.......Server PID : $1"
echo "============================="
echo "send alphabets (26 characters - 26 bytes)"
time ./client $1 "$alphabets"
echo "============================="
echo "send numbers (10 characters - 10 bytes)"
time ./client $1 "$numbers"
echo "============================="
echo "send korean (42 characters - 126 bytes)"
time ./client $1 "$korean"
echo "============================="
echo "send emoji (57 characters - 228 bytes)"
time ./client $1 "$emoji"
echo "============================="
echo "send test_str (466 characters - 466 bytes)"
time ./client $1 "$test_str"
