RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applywaitmovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Pfff, elke dag weer zo moeilijk...\p"
	.string "Wat moeilijk is?\n"
	.string "Moet je dat nog vragen?\p"
	.string "Bedenken wat we vandaag eten!\p"
	.string "Het is echt niet makkelijk om\n"
	.string "elke dag iets nieuws te bedenken.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Hallo! Welkom bij de familie PEPPER.\p"
	.string "Ik heb een vraag voor je.\n"
	.string "Heb jij weleens opgepast?\p"
	.string "Ik ben net vader geworden.\n"
	.string "Een kind opvoeden is nieuw voor mij.\p"
	.string "Mijn dochter WALDA lacht te weinig.\p"
	.string "Misschien lacht ze als ik iets\n"
	.string "grappigs tegen haar zeg.\p"
	.string "Ken jij een grappig woord\n"
	.string "of een leuke zin?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Ik zeg de laatste tijd\n"
	.string "“{STR_VAR_1}” tegen haar.\p"
	.string "Weet jij iets grappigers\n"
	.string "dat misschien werkt?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "O, geweldig!\n"
	.string "Vertel me jouw idee maar.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "O, echt?\p"
	.string "Als je iets leuks bedenkt,\n"
	.string "wil ik het graag horen.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, ik snap het.\n"
	.string "Laten we het proberen!$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Ja! Ze lacht!\n"
	.string "Ik ben net zo blij als zij!$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, ik snap het.\n"
	.string "Laten we het proberen!$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmm... Ze lacht helemaal niet.\n"
	.string "WALDA is vast een serieus kind.$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "O, je weet niets grappigs.\n"
	.string "Dan bedenk ik zelf wel iets.\p"
	.string "Hmm... Wat dacht je van\n"
	.string "“{STR_VAR_1}”?\p"
	.string "Eens kijken of dat werkt.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmm... Ze lacht helemaal niet.\n"
	.string "WALDA is vast een serieus kind.$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "O, je weet niets grappigs.\p"
	.string "Dan probeer ik het woord\n"
	.string "van de vorige keer nog eens.\p"
	.string "Als je iets leuks bedenkt,\n"
	.string "vertel het me dan gerust!$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Bedankt!\p"
	.string "Dankzij jou heeft mijn lieve\n"
	.string "WALDA gelachen!\p"
	.string "Je zou het misschien niet denken,\n"
	.string "maar ik ben een van de beste\l"
	.string "onderzoekers van DEVON.\p"
	.string "Ik wil graag iets terugdoen.\p"
	.string "Ik voeg nieuwe achtergronden\n"
	.string "toe aan de BOXES in de PC.\p"
	.string "Kies FRIENDS in het menu\n"
	.string "voor achtergronden.\p"
	.string "Daar vind je de nieuwe patronen!$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "Het is een Pokémon-knuffel!$"

