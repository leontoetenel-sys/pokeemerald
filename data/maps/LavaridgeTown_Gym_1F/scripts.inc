LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_GERALD, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_AXLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_DANIELLE, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_LAVARIDGE_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_LAVARIDGE_TOWN_STATE, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_FLANNERY_1, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_AXLE, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_DANIELLE, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_GERALD, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JACE, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hé, hoe gaat het, toekomstige\n"
	.string "kampioen {PLAYER}?\p"
	.string "FLANNERY, de Gymleider van\n"
	.string "LAVARIDGE, gebruikt Pokémon\l"
	.string "van het FIRE-type.\p"
	.string "Haar liefde voor Pokémon\n"
	.string "brandt heter dan een vulkaan!\p"
	.string "Kom niet te dichtbij, anders\n"
	.string "verbrand je nog!\p"
	.string "Blus haar vuur met water\n"
	.string "en ga ervoor!$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Wauw! Dat was een gloeiend\n"
	.string "heet duel!$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Auauauau!\n"
	.string "Jeetje, wat heet!$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Ik zie niets meer door het\n"
	.string "zweet in mijn ogen...$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "In warm zand liggen is goed\n"
	.string "voor je bloedsomloop.\p"
	.string "Het helpt tegen pijn in\n"
	.string "je gewrichten.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "Ik probeer te ontspannen.\n"
	.string "Kom me nou niet stressen!$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "Ik hoop dat FLANNERY je\n"
	.string "flink laat zweten!$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah... Poeh...\p"
	.string "Als je te lang in warm zand\n"
	.string "ligt, word je helemaal moe...$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Je bent vast al moe.\n"
	.string "Je wilt zeker even uitrusten\l"
	.string "in het warme zand?\p"
	.string "Maar doorzetten is een\n"
	.string "belangrijke eigenschap\l"
	.string "voor elke trainer.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Wie met vuur speelt,\n"
	.string "kan zich branden...$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Je bent echt goed...\p"
	.string "Maar onze Gymleider FLANNERY\n"
	.string "is sterk.\p"
	.string "Pas maar op dat je je niet\n"
	.string "flink brandt!$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Kunnen jouw Pokémon tegen\n"
	.string "een hitte van 392 graden?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Het vuur was niet heet genoeg...$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "Magma is 392 graden heet.\p"
	.string "Jouw Pokémon hebben me\n"
	.string "verslagen, dus die kunnen\l"
	.string "vast tegen magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Eh...\n"
	.string "Goed, ik vecht tegen je.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "O, maar jij bent veel te sterk.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Ik wil een mooie, sterke\n"
	.string "trainer worden, net als FLANNERY.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Kom op, schiet eens op!\n"
	.string "Voor mijn enthousiasme afkoelt!$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Het is hier zo heet, maar\n"
	.string "mijn hart voelt ijskoud...$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "Met zo'n vurige vechtlust\n"
	.string "maak je misschien wel kans\l"
	.string "tegen onze Gymleider.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Zie je hoe wild de vlammen\n"
	.string "laaien?\p"
	.string "Ze vieren mijn overwinning al!$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Er ging iets niet goed.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Nou en? Wat maakt het uit?\n"
	.string "Ik kan op blote voeten over\l"
	.string "hete kolen lopen!\p"
	.string "...Probeer dat zelf maar niet!$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Ik hou van bergen, maar\n"
	.string "vooral van vulkanen.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Volgens mij heb ik verloren\n"
	.string "zonder ooit de baas te zijn\l"
	.string "in dit duel.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Ik blijf hier omdat ik fan ben\n"
	.string "van de kracht van FLANNERY.\p"
	.string "Hehehehe.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Welkom... Nee, wacht.\p"
	.string "Nietige trainer, wat goed\n"
	.string "dat je hier bent gekomen!\p"
	.string "Aan mij is de taak gegeven...\n"
	.string "Nee, wacht even.\p"
	.string "Ik ben FLANNERY, de Gymleider\n"
	.string "van deze GYM!\p"
	.string "Eh... Onderschat me niet,\n"
	.string "ook al ben ik pas sinds kort\l"
	.string "Gymleider!\p"
	.string "Met alles wat ik van mijn\n"
	.string "grootvader heb geleerd, zal ik\l"
	.string "je, eh... onze vurige aanvallen\l"
	.string "laten zien!$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "O...\n"
	.string "Ik deed geloof ik te hard\l"
	.string "mijn best...\p"
	.string "Ik ben... Ik ben nog maar\n"
	.string "net Gymleider.\p"
	.string "Ik probeerde iemand te zijn\n"
	.string "die ik helemaal niet ben.\p"
	.string "Ik moet gewoon mezelf zijn.\n"
	.string "Anders raken mijn Pokémon\l"
	.string "in de war.\p"
	.string "Bedankt dat je me dat hebt\n"
	.string "geleerd. Dit heb je verdiend.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} kreeg de HEAT BADGE\n"
	.string "van FLANNERY.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Met de HEAT BADGE luisteren\n"
	.string "alle Pokémon tot Level 50\l"
	.string "naar je, ook geruilde Pokémon.\p"
	.string "Je kunt de HM-aanval STRENGTH\n"
	.string "nu ook buiten duels gebruiken.\p"
	.string "Dit is een bedankje van mij.\n"
	.string "Neem het gerust aan!$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "In TM50 zit OVERHEAT.\p"
	.string "Die aanval doet de tegenstander\n"
	.string "heel veel schade.\p"
	.string "Maar de SP. ATK van de Pokémon\n"
	.string "die hem gebruikt, daalt sterk.\p"
	.string "Niet zo handig in lange duels.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "GYMLEIDER FLANNERY is\n"
	.string "geregistreerd in de PokéNav.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Jouw kracht doet me aan\n"
	.string "iemand denken...\p"
	.string "O! Ik weet het! Je vecht net\n"
	.string "als NORMAN, de Gymleider\l"
	.string "van PETALBURG.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "LAVARIDGE TOWN POKéMON GYM$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "LAVARIDGE TOWN POKéMON GYM\p"
	.string "TRAINERS DIE FLANNERY VERSLOEGEN:\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY: Van een nederlaag\n"
	.string "raak ik niet ontmoedigd.\p"
	.string "Ik hou van Pokémon.\n"
	.string "Ik hou van duels.\l"
	.string "En... ik hou van deze GYM!\p"
	.string "Laten we weer een duel houden\n"
	.string "met gloeiend hete aanvallen!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Poeh!\n"
	.string "Bijna een vulkaanuitbarsting!$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY: Ik heb verloren,\n"
	.string "maar ik ben helemaal tevreden.\p"
	.string "Zo'n vurig duel maak ik\n"
	.string "niet vaak mee.\p"
	.string "Laten we dit nog eens doen!$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "FLANNERY: Van een nederlaag\n"
	.string "raak ik niet ontmoedigd.\p"
	.string "Ik hou van Pokémon.\n"
	.string "Ik hou van duels.\l"
	.string "En... ik hou van deze GYM!\p"
	.string "Laten we weer een duel houden\n"
	.string "met gloeiend hete aanvallen!\p"
	.string "O, wacht. Heb je maar één\n"
	.string "Pokémon die kan vechten?\p"
	.string "Sorry, maar neem minstens\n"
	.string "twee Pokémon mee als je\l"
	.string "terugkomt.$"
