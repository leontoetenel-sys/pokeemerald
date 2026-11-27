MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceUp
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreen FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applywaitmovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applywaitmovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro:
	.string "Nee! Die lui van TEAM MAGMA\n"
	.string "waren hier eerder dan wij!\p"
	.string "We mogen niet achterblijven!$"

MtPyre_Summit_Text_Grunt1Defeat:
	.string "Ik dacht dat je een teruggekeerd\n"
	.string "lid van TEAM MAGMA was...$"

MtPyre_Summit_Text_Grunt1PostBattle:
	.string "Oké, jij bent sterk...\n"
	.string "Maar wij zijn met veel meer!$"

MtPyre_Summit_Text_Grunt2Intro:
	.string "Ha! Pech voor jou!\p"
	.string "Als je eerder was gekomen,\n"
	.string "had je alleen tegen dat slappe\l"
	.string "TEAM MAGMA hoeven vechten.\p"
	.string "We hebben wat verrassingen\n"
	.string "gevonden in de berg!$"

MtPyre_Summit_Text_Grunt2Defeat:
	.string "Urgh... Ik had je eerst tegen\n"
	.string "TEAM MAGMA moeten laten vechten...$"

MtPyre_Summit_Text_Grunt2PostBattle:
	.string "Je weet helemaal niets!\n"
	.string "Waarom bemoei je je met ons?$"

MtPyre_Summit_Text_Grunt3Intro:
	.string "Jij...\p"
	.string "Ik heb dan wel geen spoken\n"
	.string "gevangen, maar ik ben nog\l"
	.string "een echte Aqua!$"

MtPyre_Summit_Text_Grunt3Defeat:
	.string "Als je iemand wilt dwarszitten,\n"
	.string "doe dat dan bij TEAM MAGMA...$"

MtPyre_Summit_Text_Grunt3PostBattle:
	.string "Heh, maakt niet uit!\n"
	.string "We hebben tijd gewonnen!\p"
	.string "De BAAS heeft vast gepakt\n"
	.string "waarvoor hij kwam!$"

MtPyre_Summit_Text_Grunt4Intro:
	.string "Ik heb hier iets gevangen\n"
	.string "wat zorgt dat je hoopte dat\l"
	.string "je bij TEAM MAGMA mocht!$"

MtPyre_Summit_Text_Grunt4Defeat:
	.string "Als je zo graag bij TEAM AQUA\n"
	.string "wil, kunnen we erover nadenken...$"

MtPyre_Summit_Text_Grunt4PostBattle:
	.string "Wij vormen samen met onze\n"
	.string "leider een geweldig team.$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo:
	.string "ARCHIE: MAXIE van TEAM MAGMA\n"
	.string "was ons voor, maar wij hebben\l"
	.string "ook wat we wilden.\p"
	.string "De RED ORB van MT. PYRE...\n"
	.string "Ik, ARCHIE, heb hem nu!\p"
	.string "Fufufu... Nu kunnen we ons\n"
	.string "grote doel bereiken!\p"
	.string "Kom op, TEAM!\n"
	.string "We gaan weg!$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis:
	.string "O nee...\n"
	.string "Dit mag niet gebeuren...\p"
	.string "Niet alleen de BLUE ORB, maar\n"
	.string "ook de RED ORB is meegenomen...\p"
	.string "De BLUE ORB en RED ORB mogen\n"
	.string "nooit gescheiden worden.\l"
	.string "Ze horen bij elkaar.\p"
	.string "Wat willen die mannen met\n"
	.string "de twee ORBS doen?\p"
	.string "... ... ... ... ... ...\p"
	.string "O ja. TEAM MAGMA kwam eerst\n"
	.string "en nam de BLUE ORB mee, toch?\p"
	.string "Ze lieten in hun haast dit\n"
	.string "voorwerp achter.\p"
	.string "Ik weet niet precies wat\n"
	.string "het is.\p"
	.string "Wil jij het hebben? Misschien\n"
	.string "komt het nog van pas.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken:
	.string "Die gemene mannen hebben de\n"
	.string "BLUE ORB en RED ORB meegenomen...\p"
	.string "Ze mogen nooit gescheiden zijn...\n"
	.string "Ik vrees dat er iets ergs gebeurt.$"

MtPyre_Summit_Text_GroudonKyogreAwakened:
	.string "O, hemel...\p"
	.string "Zijn GROUDON en KYOGRE\n"
	.string "allebei ontwaakt?\p"
	.string "Volgens de verhalen kalmeerden\n"
	.string "de BLUE ORB en de RED ORB\l"
	.string "die twee POKéMON ooit...\p"
	.string "Ook wordt gezegd dat de echte\n"
	.string "eigenaar van de ORBS nog bestaat.\p"
	.string "Maar niemand weet precies aan\n"
	.string "wie of wat de ORBS toebehoren.\p"
	.string "Een mens, misschien een POKéMON...\n"
	.string "Niemand weet het.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs:
	.string "De twee mannen die de ORBS\n"
	.string "meenamen, brachten ze zelf terug.\p"
	.string "Misschien zijn die mannen\n"
	.string "toch niet zo slecht...$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs:
	.string "De belichamingen van het land,\n"
	.string "de zee en de lucht...\p"
	.string "Zo worden de oeroude POKéMON\n"
	.string "volgens de verhalen genoemd...\p"
	.string "Net als mensen en POKéMON\n"
	.string "heeft ook onze wereld leven...\p"
	.string "Dat hebben de oeroude POKéMON\n"
	.string "ons geleerd...$"

MtPyre_Summit_Text_WillYouHearOutMyTale:
	.string "Op MT. PYRE brengen we de\n"
	.string "geesten van overleden POKéMON\l"
	.string "tot rust...\p"
	.string "Vanaf deze hoge plek kun je\n"
	.string "heel HOENN zien...\p"
	.string "Misschien vinden de geesten\n"
	.string "van POKéMON hier troost...\p"
	.string "Zou het toeval zijn dat\n"
	.string "je hier bent?\p"
	.string "Wil je luisteren naar een oud\n"
	.string "verhaal uit de streek HOENN?$"

MtPyre_Summit_Text_GroudonKyogreTale:
	.string "Heel, heel lang geleden...\p"
	.string "De wereld werd opgeschrikt door\n"
	.string "een hevig gevecht tussen de\l"
	.string "POKéMON van land en zee...\p"
	.string "De POKéMON van het land maakte\n"
	.string "bergen en werelddelen...\p"
	.string "De POKéMON van de zee maakte\n"
	.string "hoge golven en oceanen...\p"
	.string "Hun felle strijd bleef maar duren.\p"
	.string "Grote branden en zware stormen\n"
	.string "overspoelden de wereld.\p"
	.string "De BLUE ORB en de RED ORB\n"
	.string "maakten een einde aan de ramp.\p"
	.string "Licht uit de twee ORBS kalmeerde\n"
	.string "de woedende tegenstanders.\p"
	.string "Daarna doken ze diep de zee in,\n"
	.string "waar ze uiteindelijk verdwenen...$"

MtPyre_Summit_Text_WellThatTooIsFine:
	.string "Ik begrijp het...\n"
	.string "Dat is ook goed...$"

MtPyre_Summit_Text_MaxieSilence:
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn:
	.string "Ik geef de verhalen van HOENN\n"
	.string "door aan volgende generaties.\p"
	.string "De crisis in SOOTOPOLIS heeft\n"
	.string "een legende veranderd...\p"
	.string "Heb je tijd om de nieuwe\n"
	.string "legende van HOENN te horen?$"

MtPyre_Summit_Text_HoennTrioTale:
	.string "Heel, heel lang geleden...\p"
	.string "De wereld werd opgeschrikt door\n"
	.string "een hevig gevecht tussen de\l"
	.string "POKéMON van land en zee...\p"
	.string "De POKéMON van het land maakte\n"
	.string "bergen en werelddelen...\p"
	.string "De POKéMON van de zee maakte\n"
	.string "hoge golven en oceanen...\p"
	.string "Hun felle strijd bleef maar duren.\p"
	.string "Grote branden en zware stormen\n"
	.string "overspoelden de wereld.\p"
	.string "Toen daalde de POKéMON van\n"
	.string "de lucht neer uit een storm.\p"
	.string "De felgroene POKéMON kalmeerde\n"
	.string "de twee woedende POKéMON.\p"
	.string "Toen zijn taak erop zat, vloog\n"
	.string "de groene POKéMON weer weg...$"

