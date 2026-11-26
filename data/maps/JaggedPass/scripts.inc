JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro:
	.string "JAGGED PASS bij MT. CHIMNEY...\p"
	.string "Dit is precies wat ik zoek\n"
	.string "in een berg!\p"
	.string "Al die hobbels en rotsen...\n"
	.string "Daar word ik helemaal blij van!$"

JaggedPass_Text_EricDefeat:
	.string "Ik baal dat ik verloren heb!$"

JaggedPass_Text_EricPostBattle:
	.string "Ja, ik heb het duel verloren...\p"
	.string "Maar niemand houdt zoveel\n"
	.string "van bergen als ik!$"

JaggedPass_Text_DianaIntro:
	.string "Dit is geen gewone wandeling.\n"
	.string "Hier kun je niet lekker picknicken.$"

JaggedPass_Text_DianaDefeat:
	.string "Ooooh, nee!\n"
	.string "De grond is veel te hobbelig...$"

JaggedPass_Text_DianaPostBattle:
	.string "Wist je dat sommige mensen\n"
	.string "met hun fiets zelfs dit\l"
	.string "hobbelige pad op kunnen rijden?$"

JaggedPass_Text_DianaRegister:
	.string "Kom je hier nog eens terug?\p"
	.string "Dan wil ik graag een rematch.$"

JaggedPass_Text_DianaRematchIntro:
	.string "Picknicken is overal leuk.\n"
	.string "Net als Pokémon!$"

JaggedPass_Text_DianaRematchDefeat:
	.string "Ik verloor alleen omdat de\n"
	.string "grond zo hobbelig is!$"

JaggedPass_Text_DianaPostRematch:
	.string "Ik vergeet mijn nederlaag\n"
	.string "en geniet van deze wandeling.$"

JaggedPass_Text_EthanIntro:
	.string "JAGGED PASS is lastig om\n"
	.string "op te lopen.\p"
	.string "Een goede plek om te trainen!$"

JaggedPass_Text_EthanDefeat:
	.string "Het duel was al voorbij\n"
	.string "voordat we stevig stonden...$"

JaggedPass_Text_EthanPostBattle:
	.string "Met een ACRO BIKE zou ik\n"
	.string "over de richels kunnen springen.$"

JaggedPass_Text_EthanRegister:
	.string "Als ik aan die hobbels gewend\n"
	.string "ben, win ik vast!\p"
	.string "Wil je me registreren in\n"
	.string "je PokéNav?$"

JaggedPass_Text_EthanRematchIntro:
	.string "Ik ben gewend aan de hobbels.\n"
	.string "Ik zing nu tijdens het klimmen!$"

JaggedPass_Text_EthanRematchDefeat:
	.string "Vechten op deze hobbelige\n"
	.string "grond blijft lastig...$"

JaggedPass_Text_EthanPostRematch:
	.string "Ik moet een ACRO BIKE halen\n"
	.string "bij RYDEL in MAUVILLE CITY...$"

JaggedPass_Text_GruntIntro:
	.string "Wah!\n"
	.string "Wat doe jij hier?\p"
	.string "Wat ik op deze plek doe?\p"
	.string "Dat gaat jou niets aan!$"

JaggedPass_Text_GruntDefeat:
	.string "Urrrgh...\p"
	.string "Ik had meteen onze geheime\n"
	.string "schuilplaats in moeten duiken...$"

JaggedPass_Text_GoWhereverYouWant:
	.string "Goed, goed!\n"
	.string "Ik geef toe dat je sterk bent!\p"
	.string "Let maar niet op mij.\n"
	.string "Ga waar je maar wilt!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem:
	.string "O! Dit rotsblok trilt door\n"
	.string "het MAGMA EMBLEM!$"

JaggedPass_Text_JulioIntro:
	.string "Aaaah! Het is doodeng om\n"
	.string "in één keer de berg af te rijden!$"

JaggedPass_Text_JulioDefeat:
	.string "Het voelt alsof ik uit elkaar\n"
	.string "val...$"

JaggedPass_Text_JulioPostBattle:
	.string "Mijn fiets stuiterde zo erg\n"
	.string "dat mijn billen pijn doen...$"

JaggedPass_Text_AutumnIntro:
	.string "Ik klim elke dag deze berg op.\n"
	.string "Ik weet zeker dat ik sterk ben!$"

JaggedPass_Text_AutumnDefeat:
	.string "Hmm...\n"
	.string "Wat ging er mis?$"

JaggedPass_Text_AutumnPostBattle:
	.string "Wat is dat vreemde stuk rots\n"
	.string "iets verder de berg op?$"

