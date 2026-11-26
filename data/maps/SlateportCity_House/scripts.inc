SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Mijn POKéMON heeft een HASTY nature.\p"
	.string "Zijn SPEED is hoger dan die\n"
	.string "van mijn andere POKéMON.\p"
	.string "Misschien bepaalt de nature\n"
	.string "welke stats sneller groeien.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Jij bent een trainer, toch?\p"
	.string "Dan ga je vast naar de BATTLE TENT\n"
	.string "hier in SLATEPORT!$"

