
echo "\n======= SO_LONG - Invalid Map File Test ======"

echo "\n존재하지 않는 파일 테스트\n파일 이름 : maps/00_no_exit.ber\n실행결과 :"
./so_long "maps/00_no_exit.ber"

echo "\n------------------------------------------------"
echo "\n잘못된 확장자 파일 테스트\n파일 이름 : maps/_01_extension.txt\n실행결과 :"
./so_long "maps/_01_extension.txt"

echo "\n------------------------------------------------"
echo "\n빈 파일 테스트\n파일 이름 : maps/_02_empty.ber\n실행결과 :"	
./so_long "maps/_02_empty.ber"

echo "\n------------------------------------------------"
echo "\n벽이 없는 경우 테스트\n파일 이름 : maps/_03_no_wall.ber\n실행결과 :"
./so_long "maps/_03_no_wall.ber"

echo "\n------------------------------------------------"
echo "\nP가 두개인 경우 테스트\n파일 이름 : maps/_04_two_player.ber\n실행결과 :"
./so_long "maps/_04_two_player.ber"

echo "\n------------------------------------------------"
echo "\nP가 두개인 경우 테스트\n파일 이름 : maps/_05_two_Exit.ber\n실행결과 :"
./so_long "maps/_05_two_Exit.ber"

echo "\n------------------------------------------------"
echo "\n승리할 수 있는 경로가 없는 경우 테스트\n파일 이름 : maps/_06_no_path.ber\n실행결과 :"
./so_long "maps/_06_no_path.ber"

echo "\n============ SO_LONG - Test End ============\n"