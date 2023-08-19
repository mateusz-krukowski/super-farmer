#pragma once


class TradeState : public State {
public:
	TradeState(Player* player, GameStateManager* gameStateManager);
	void run() override;

	void tradeRabbitsForSheep();
	void tradeSheepForRabbits();
	void tradeSheepForSmallDog();
	void tradeSmallDogForSheep();
	void tradeSheepsForPig();
	void tradePigForSheeps();
	void tradePigsForCow();
	void tradeCowForBigDog();
	void tradeBigDogForCow();
	void tradeCowsForHorse();
	void tradeHorseForCows();

};