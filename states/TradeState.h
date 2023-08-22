#pragma once


class TradeState : public State {
public:
	TradeState(GameStateManager* gameStateManager);
	void run() override;

};