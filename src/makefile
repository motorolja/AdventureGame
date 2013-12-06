#
# Makefile för AdventureGame
#

CCC	= g++ -std=c++11
LFLAGS	= -lncurses

all: text_adventure_game input_test player_test

text_adventure_game: main.cpp adventure_game.o text_system_input.o output.o engine.o message.o room.o player.o position.o command_parser.o
	$(CCC) -o text_adventure_game main.cpp adventure_game.o text_system_input.o output.o engine.o message.o room.o player.o position.o command_parser.o $(LFLAGS)

player_test: test_player.cpp player.o item.o position.o
	$(CCC) -o player_test test_player.cpp player.o item.o position.o

input_test: test_text_system_input.cpp message.o room.o player.o position.o text_input_system.o command_parser.o
	$(CCC) -o input_test test_text_system_input.cpp message.o room.o player.o position.o text_input_system.o command_parser.o $(LFLAGS)

room.o: room.cpp
	$(CCC) -c room.cpp

player.o: player.cpp
	$(CCC) -c player.cpp

position.o: position.cpp
	$(CCC) -c position.cpp

adventure_game.o: adventure_game.cpp
	$(CCC) -c adventure_game.cpp

text_system_input.o: text_input_system.cpp
	$(CCC) -c text_input_system.cpp

command_parser.o: command_parser.cpp
	$(CCC) -c command_parser.cpp

output.o: text_output_system.cpp
	$(CCC) -c text_output_system.cpp

engine.o: engine.cpp
	$(CCC) -c engine.cpp

world.o: world.cpp
	$(CCC) -c world.cpp

item.o: item.cpp
	$(CCC) -c item.cpp

message.o: message.cpp
	$(CCC) -c message.cpp

clean:
	rm -rf *.o
