#pragma once


class TradeState : public State {
public:
	TradeState(Player* player, GameStateManager* gameStateManager);
	void run() override;

};