MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applywaitmovement LOCALID_PLAYER, Common_Movement_FaceDown
	delay 30
	applywaitmovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applywaitmovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	applywaitmovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_Delay48
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applywaitmovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_METEOR_FALLS_ARCHIE
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	addobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_MAGMA_GRUNT_2
	applywaitmovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applywaitmovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applywaitmovement LOCALID_METEOR_FALLS_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_METEOR_FALLS_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_METEOR_FALLS_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_METEOR_FALLS_ARCHIE
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_1
	removeobject LOCALID_METEOR_FALLS_AQUA_GRUNT_2
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "Hehehe!\p"
	.string "Met deze METEORITE zal dat\n"
	.string "ding in MT. CHIMNEY...$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "Hè?\p"
	.string "Ik weet niet wie je bent, maar\n"
	.string "als je TEAM MAGMA in de weg\l"
	.string "zit, krijg je geen genade!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "Geen stap verder, TEAM MAGMA!\p"
	.string "Jullie denken toch niet echt\n"
	.string "dat de wereld van jullie is?$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "Hehehe!\n"
	.string "Zelfs TEAM AQUA is erbij!\p"
	.string "Maar het kost te veel moeite\n"
	.string "om jullie allemaal te verslaan.\p"
	.string "Ach, het maakt niet uit!\p"
	.string "We hebben de METEORITE.\n"
	.string "Op naar MT. CHIMNEY!\p"
	.string "Hehehe! Tot ziens, stelletje\n"
	.string "klunzen van TEAM AQUA!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "ARCHIE: Heb ik jou niet eerder\n"
	.string "gezien in het museum in SLATEPORT?\p"
	.string "Dus jij heet {PLAYER}.\p"
	.string "Toen dacht ik dat je bij\n"
	.string "TEAM MAGMA hoorde.\p"
	.string "Hm... Jij bent een vreemd kind.\p"
	.string "TEAM MAGMA is een gevaarlijke\n"
	.string "groep fanatiekelingen.\p"
	.string "Ze vernielen van alles omdat\n"
	.string "ze meer land willen maken.\p"
	.string "Ze zijn de vijanden van ons,\n"
	.string "TEAM AQUA, dat van de zee houdt!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "BAAS, we moeten achter\n"
	.string "TEAM MAGMA aan...$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "ARCHIE: Ja, inderdaad!\n"
	.string "We moeten opschieten.\p"
	.string "Wie weet wat TEAM MAGMA\n"
	.string "bij MT. CHIMNEY gaat doen!$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "ARCHIE: {PLAYER}, hou jij\n"
	.string "TEAM MAGMA ook in de gaten.\p"
	.string "Tot ziens!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "Ik... Ik ben COZMO.\n"
	.string "Ik ben professor...\p"
	.string "TEAM MAGMA vroeg me om hen\n"
	.string "naar METEOR FALLS te brengen.\p"
	.string "Maar ze hebben me bedrogen.\n"
	.string "Ze stalen zelfs mijn METEORITE!\p"
	.string "Toen kwam er nog zo'n groep,\n"
	.string "TEAM AQUA.\p"
	.string "Daarna...\n"
	.string "Ik snap er helemaal niets van.\p"
	.string "Maar TEAM MAGMA...\p"
	.string "Wat willen ze met die METEORITE\n"
	.string "bij MT. CHIMNEY doen?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "PROF. COZMO: Maar TEAM MAGMA...\p"
	.string "Wat willen ze met die METEORITE\n"
	.string "bij MT. CHIMNEY doen?$"
