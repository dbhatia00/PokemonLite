GCC = g++ -g

main: test.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o Model.o GameCommand.o View.o Rival.o BattleArena.o
	$(GCC) test.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o Model.o GameCommand.o View.o Rival.o BattleArena.o -o main

test.o: test.cpp
	$(GCC) -c test.cpp

Point2D.o: Point2D.cpp
	$(GCC) -c Point2D.cpp

Vector2D.o: Vector2D.cpp
	$(GCC) -c Vector2D.cpp

GameObject.o: GameObject.cpp
	$(GCC) -c GameObject.cpp

Building.o: Building.cpp
	$(GCC) -c Building.cpp

PokemonCenter.o: PokemonCenter.cpp
	$(GCC) -c PokemonCenter.cpp

Pokemon.o: Pokemon.cpp
	$(GCC) -c Pokemon.cpp

PokemonGym.o: PokemonGym.cpp
	$(GCC) -c PokemonGym.cpp

Model.o: Model.cpp
	$(GCC) -c Model.cpp

GameCommand.o: GameCommand.cpp
	$(GCC) -c GameCommand.cpp

View.o: View.cpp
	$(GCC) -c View.cpp

Rival.o: Rival.cpp
	$(GCC) -c Rival.cpp
	
BattleArena.o: BattleArena.cpp
	$(GCC) -c BattleArena.cpp
	
clean:
	rm test.o Point2D.o Vector2D.o GameObject.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o Model.o GameCommand.o View.o Rival.o BattleArena.o main