MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_Delay48
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_METEOR_FALLS_STEVEN
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applywaitmovement LOCALID_METEOR_FALLS_STEVEN, Common_Movement_FacePlayer
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "STEVEN: Wauw, {PLAYER}!\n"
	.string "Knap dat je me hebt gevonden.\p"
	.string "Denk je soms dat ik alleen\n"
	.string "maar dol ben op stenen?\p"
	.string "Nee, dat kan haast niet.\p"
	.string "We vochten samen in het\n"
	.string "SPACE CENTER van SOOTOPOLIS.\p"
	.string "Je weet dus vast wel hoe\n"
	.string "sterk ik ben.\p"
	.string "Goed, {PLAYER}, als je me echt\n"
	.string "wilt uitdagen, bereid je dan\l"
	.string "maar voor op een zwaar duel!$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Jij...\n"
	.string "Ik wist niet dat je zo sterk\l"
	.string "was geworden...$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "STEVEN: Toen we elkaar voor\n"
	.string "het eerst ontmoetten in\l"
	.string "GRANITE CAVE bij DEWFORD,\l"
	.string "had ik al zo'n gevoel.\p"
	.string "Ik dacht dat jij ooit de\n"
	.string "kampioen zou worden.\p"
	.string "Mijn voorspellingen komen\n"
	.string "meestal uit.\p"
	.string "En waar ga je nu naartoe?\p"
	.string "... ... ... ... ... ...\n"
	.string "... ... ... ... ... ...\p"
	.string "Hehehe, zelfs ik weet dat niet.$"

