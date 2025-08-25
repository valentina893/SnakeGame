build_position:
	gcc -c src/position/position.c -o src/position/position.o

build_position_tests:
	gcc src/position/position_tests.c src/position/position.o -o src/position/position_tests

run_position_tests:
	./src/position/position_tests

build_snake:
	gcc -c src/snake/snake.c -Isrc/position/position.o -o src/snake/snake.o

build_snake_tests:
	gcc src/snake/snake_tests.c src/snake/snake.o src/position/position.o -o src/snake/snake_tests

run_snake_tests:
	./src/snake/snake_tests

build_board:
	gcc -c src/board/board.c -Ilib/matrix/matrix.o -o src/board/board.o

build_board_tests:
	gcc src/board/board_tests.c src/board/board.o  lib/matrix/matrix.o -o src/board/board_tests

run_board_tests:
	./src/board/board_tests

build_apple:
	gcc -c src/apple/apple.c -Isrc/position/position.o -Ilib/random/random.o -o src/apple/apple.o

build_apple_tests:
	gcc src/apple/apple_tests.c src/apple/apple.o src/position/position.o lib/random/random.o -o src/apple/apple_tests

run_apple_tests:
	./src/apple/apple_tests

build_game:
	gcc -c src/game/game.c -Isrc/apple/apple.o -Isrc/board/board.o -Isrc/position/position.o -Isrc/snake/snake.o -Ilib/matrix/matrix.o -Ilib/random/random.o -o src/game/game.o

build_game_tests:
	gcc src/game/game_tests.c src/game/game.o src/apple/apple.o src/board/board.o src/position/position.o src/snake/snake.o lib/matrix/matrix.o lib/random/random.o -o src/game/game_tests

run_game_tests:
	./src/game/game_tests

build_snake_game:
	gcc src/snake_main.c src/game/game.o src/apple/apple.o src/board/board.o src/position/position.o src/snake/snake.o lib/matrix/matrix.o lib/random/random.o -o builds/snake1