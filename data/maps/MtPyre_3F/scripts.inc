MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "De bijzondere sfeer op deze berg\n"
	.string "heeft mijn krachten versterkt!\p"
	.string "Denk jij als kind echt\n"
	.string "dat je kunt winnen?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Ik verdrink in zelfmedelijden...$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Mijn krachten zijn vast veel\n"
	.string "sterker geworden, maar toch...$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Dit is geen plek voor kinderen,\n"
	.string "en al helemaal niet voor jou!$"

MtPyre_3F_Text_KaylaDefeat:
	.string "Ik heb zomaar verloren...$"

MtPyre_3F_Text_KaylaPostBattle:
	.string "Ik heb nog niet genoeg getraind...\p"
	.string "Ik moet blijven werken om\n"
	.string "de top te bereiken...\p"
	.string "Kom op, ik kan het!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Waarom ben je hier gekomen?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Wat geweldig!\n"
	.string "Jij bent een bijzondere TRAINER.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON die er niet meer zijn.\n"
	.string "POKéMON die nu bij je zijn.\p"
	.string "En de POKéMON die je later\n"
	.string "nog zult ontmoeten...\p"
	.string "Ze verdienen allemaal evenveel\n"
	.string "liefde. Onthoud dat goed.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Ik wil je POKéMON graag weer\n"
	.string "zien als ze sterker zijn...\p"
	.string "Mag ik even je POKéNAV zien?$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "O, jij bent het...\p"
	.string "Kom je me laten zien hoe je\n"
	.string "POKéMON zijn gegroeid?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Wat geweldig!\n"
	.string "Jij bent een bijzonder mens.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON die er niet meer zijn.\n"
	.string "POKéMON die nu bij je zijn.\p"
	.string "En de POKéMON die je later\n"
	.string "nog zult ontmoeten...\p"
	.string "Ze verdienen allemaal evenveel\n"
	.string "liefde. Je hebt dat onthouden.$"

