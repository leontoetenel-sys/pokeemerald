RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_CITY_STATE, 1
	addvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	msgbox RustboroCity_Gym_Text_ExplainRockTomb, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "He, hoe gaat het?\p"
	.string "Luister eens, vriend!\n"
	.string "Wil jij kampioen worden?\p"
	.string "Ik ben zelf geen trainer, maar\n"
	.string "ik kan je wel goede tips geven.\p"
	.string "Samen gaan we voor het\n"
	.string "POKéMON CHAMPIONSHIP!\p"
	.string "Als trainer moet je GYM BADGES\n"
	.string "verzamelen, toch?\p"
	.string "Maar GYM LEADERS zijn niet makkelijk!\p"
	.string "Daarom ben ik hier om je\n"
	.string "goede tips te geven!\p"
	.string "ROXANNE gebruikt ROCK-type\n"
	.string "Pokémon.\p"
	.string "Die kunnen veel hebben, maar\n"
	.string "zijn zwak tegen WATER- en\l"
	.string "GRASS-type aanvallen.\p"
	.string "Kom na je overwinning weer\n"
	.string "even bij me langs.\p"
	.string "Zet hem op!$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Wauw! Wat een geweldige zege!\n"
	.string "Mijn aanmoediging heeft geholpen!\p"
	.string "Kijk eens op je TRAINER CARD.\p"
	.string "Daar staat nu je STONE BADGE op.\p"
	.string "Je hebt je eerste stap gezet\n"
	.string "op weg naar het kampioenschap!\p"
	.string "Dat voelt vast geweldig!$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Onderschat ons GYM TRAINERS niet!\n"
	.string "Ik zal je laten zien hoe sterk we zijn!$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Jij was te goed voor mij...$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Je hebt nog lang niet gezien\n"
	.string "hoe sterk ROCK-type Pokémon zijn!$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Als je mij niet kunt verslaan,\n"
	.string "maak je geen kans tegen ROXANNE!$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Wauw! Jij hebt echt talent!$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE is veel sterker dan ik.\p"
	.string "Je bent gewaarschuwd!$"

RustboroCity_Gym_Text_MarcIntro:
	.string "We zitten midden in de stad,\n"
	.string "maar wat maakt dat uit?\p"
	.string "Mijn ROCK-type Pokémon willen\n"
	.string "lekker tekeergaan!$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "O man, o man!\n"
	.string "Onze uitdager is echt pittig!$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Onze GYM LEADER is heel slim.\p"
	.string "Ze wist al op jonge leeftijd\n"
	.string "dat ROCK een sterk type is.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Hallo, ik ben ROXANNE, de\n"
	.string "GYM LEADER van RUSTBORO.\p"
	.string "Op de Pokémon-trainersschool\n"
	.string "heb ik veel geleerd.\p"
	.string "Als GYM LEADER kan ik dat\n"
	.string "allemaal gebruiken in gevechten.\p"
	.string "Wil je me laten zien hoe jij\n"
	.string "met je Pokémon vecht?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Dus... Ik heb verloren...\p"
	.string "Ik heb blijkbaar nog veel\n"
	.string "te leren.\p"
	.string "Ik begrijp het.\p"
	.string "Volgens de regels van de\n"
	.string "POKéMON LEAGUE krijg je een\l"
	.string "BADGE als je een GYM LEADER verslaat.\p"
	.string "Hier is jouw officiële\n"
	.string "STONE BADGE!$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} krijgt de STONE BADGE\n"
	.string "van ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "De STONE BADGE verhoogt de\n"
	.string "ATTACK van je Pokémon.\p"
	.string "Je kunt nu ook CUT buiten\n"
	.string "gevechten gebruiken.\p"
	.string "Neem dit ook maar mee.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "In TM39 zit ROCK TOMB.\p"
	.string "Je laat stenen op de vijand vallen.\n"
	.string "Dat doet schade en verlaagt SPEED.\p"
	.string "Met een TM leert je Pokémon\n"
	.string "meteen een nieuwe aanval.\p"
	.string "Je kunt een TM maar één keer\n"
	.string "gebruiken. Denk dus goed na!$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Je bent zo sterk dat je ook\n"
	.string "andere GYM LEADERS moet uitdagen.\p"
	.string "Van gevechten met veel trainers\n"
	.string "kun je veel leren.$"

RustboroCity_Gym_Text_GymStatue:
	.string "RUSTBORO CITY POKéMON GYM$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "RUSTBORO CITY POKéMON GYM\p"
	.string "TRAINERS DIE ROXANNE VERSLOEGEN:\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "... ... ... ...\n"
	.string "... ... ... Piep!\p"
	.string "ROXANNE: Hallo, {PLAYER}?\n"
	.string "Met ROXANNE uit RUSTBORO CITY.\p"
	.string "BRAWLY vertelde me dat je\n"
	.string "razendsnel beter wordt als trainer.\p"
	.string "Maar ik wil nog steeds geloven\n"
	.string "dat ik je kan verslaan!\p"
	.string "Ik ga hard trainen in mijn GYM,\n"
	.string "zodat je ons opnieuw kunt uitdagen.\p"
	.string "Ik hoop dat jij er net zoveel\n"
	.string "zin in hebt als ik!\p"
	.string "... ... ... Klik!$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "GYM LEADER ROXANNE is toegevoegd\n"
	.string "aan de POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE: Wat fijn je weer te zien!\n"
	.string "Ik ben ROXANNE, de GYM LEADER.\p"
	.string "We hebben vast allebei veel\n"
	.string "gevechten gehad sinds de vorige keer.\p"
	.string "Ik wil zien hoeveel beter we\n"
	.string "zijn geworden. Kom maar op!$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr... Alweer verloren...$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE: Ik heb nog veel te leren\n"
	.string "over Pokémon-gevechten.\p"
	.string "En juist daarom vind ik\n"
	.string "vechten zo leuk!$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE: Wat fijn je weer te zien!\n"
	.string "Ik ben ROXANNE, de GYM LEADER.\p"
	.string "We hebben vast allebei veel\n"
	.string "gevechten gehad sinds de vorige keer.\p"
	.string "Ik wil zien hoeveel beter we\n"
	.string "zijn geworden...\p"
	.string "O nee... Heb je maar één Pokémon?\p"
	.string "Kom terug met minstens twee\n"
	.string "Pokémon.$"
