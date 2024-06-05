
echo "
======= SO_LONG - Invalid Map File Test ======
"

echo "- 존재하지 않는 파일 테스트
- 파일 이름 : maps/00_no_exit.ber
- 실행결과 :"
./so_long "maps/00_no_exit.ber"

echo "
------------------------------------------------
"
echo "잘못된 확장자 파일 테스트
파일 이름 : maps/_01_extension.txt
실행결과 :"
./so_long "maps/_01_extension.txt"

echo "
------------------------------------------------
"
echo "빈 파일 테스트
파일 이름 : maps/_02_empty.ber
실행결과 :"	
./so_long "maps/_02_empty.ber"

echo "
------------------------------------------------
"
echo "벽이 없는 경우 테스트
파일 이름 : maps/_03_no_wall.ber
실행결과 :"
./so_long "maps/_03_no_wall.ber"

echo "
------------------------------------------------
"
echo "P가 두개인 경우 테스트
파일 이름 : maps/_04_two_player.ber
실행결과 :"
./so_long "maps/_04_two_player.ber"

echo "
------------------------------------------------
"
echo "E가 두개인 경우 테스트
파일 이름 : maps/_05_two_Exit.ber
실행결과 :"
./so_long "maps/_05_two_Exit.ber"

echo "
------------------------------------------------
"
echo "경로가 없는 경우 테스트
파일 이름 : maps/_06_no_path.ber
실행결과 :"
./so_long "maps/_06_no_path.ber"


echo "
============ SO_LONG - Test End ===========
"