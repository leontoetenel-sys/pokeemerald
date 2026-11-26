PetalburgCity_Mart_MapScripts::
	.byte 0

PetalburgCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_ExpandedItems
	pokemart PetalburgCity_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Basic:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_ExpandedItems::
	pokemart PetalburgCity_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_ORANGE_MAIL
	pokemartlistend

PetalburgCity_Mart_EventScript_Woman::
	msgbox PetalburgCity_Mart_Text_WeakWillGrowStronger, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Boy::
	msgbox PetalburgCity_Mart_Text_RepelIsUseful, MSGBOX_NPC
	end

PetalburgCity_Mart_EventScript_Man::
	msgbox PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou, MSGBOX_NPC
	end

PetalburgCity_Mart_Text_WeakWillGrowStronger:
	.string "Ook een zwakke Pokémon kan\n"
	.string "heel sterk worden.\p"
	.string "Het belangrijkste is liefde!\n"
	.string "Liefde voor je Pokémon!$"

PetalburgCity_Mart_Text_RepelIsUseful:
	.string "Gebruik je REPEL?\n"
	.string "Het houdt Pokémon op afstand.\p"
	.string "Handig als je haast hebt!$"

PetalburgCity_Mart_Text_TakeSomeAntidotesWithYou:
	.string "Heb je ANTIDOTES bij je?\p"
	.string "Een poisoned Pokémon verliest\n"
	.string "HP tijdens het lopen.\p"
	.string "Hij kan zelfs flauwvallen.\n"
	.string "Neem dus ANTIDOTES mee!$"

