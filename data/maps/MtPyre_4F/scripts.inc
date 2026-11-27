MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro:
	.string "Meester...\n"
	.string "Kijk alstublieft hoe ik groei!$"

MtPyre_5F_Text_AtsushiDefeat:
	.string "Meester...\n"
	.string "Vergeef me alstublieft!$"

MtPyre_5F_Text_AtsushiPostBattle:
	.string "Mijn meester rust hier. Tot ik\n"
	.string "beter word, vindt hij geen rust...$"

