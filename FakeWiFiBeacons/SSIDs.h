#ifndef SSIDs_h
#define SSIDs_h

/*
   This file contains all predefined lists of SSIDs.
 */

extern "C" {
#include "user_interface.h"
}

/*-----------constants-----------*/
const bool randomChannel = true;  // Send on random channels
const int channel = 11;           // Default channel if randomChannel=false

const int maxListSize = 228; 	    // Max. list size
const int maxNameLen = 33;		    // Max. SSID name length (includes NULL char)

/*--------data structures--------*/
struct SSID
{
  uint8_t nameSize;               // Size of ssid name
  uint8_t channel;                // Channel
  uint8_t sourceMACaddress[6];    // Source MAC address
  uint8_t BSSID[6];               // BSSID MAC address
};

int ssidNum = maxListSize;
String ssid;

struct SSID ssids[maxListSize];

/*------------- Wi-Fi and Broadband poem --------------*/
char ssidWifiAndBroadband[][maxNameLen] = {
  "a) -- Wi-Fi and Broadband poem -",
  "b) Some men are crazy,",
  "c) they manage without a wife",
  "d) but not without Wi-Fi.",
  "e) Some women are crazy,",
  "f) they manage without a husband",
  "g) but not without broadband.",
  "h) When for a spouse",
  "i) they should have a look,",
  "j) they only have Facebook"
};
int ssidWifiAndBroadbandSize = sizeof(ssidWifiAndBroadband) / maxNameLen; // Number of entries

/*------------------- RickRoll song -------------------*/
char ssidRickRoll[][maxNameLen] = {
  "0) ----- RickRoll song ---------",  
  "1) Never gonna give you up,",  
  "2) never gonna let you down",
  "3) Never gonna run around",
  "4)  and desert you.",
  "5) Never gonna make you cry,",
  "6) never gonna say goodbye",
  "7) Never gonna tell a lie",
  "8)  and hurt you."
};
int ssidRickRollSize = sizeof(ssidRickRoll) / maxNameLen; // Number of entries
  
/*------------------- Funny SSIDs -------------------*/
char ssidFunny[][maxNameLen] = {
  "Little House on the Pairie",
  "(.)(.) Boobies",
  "GetOffMyLawn",
  "Go Home Tourists",
  "Will U Marry Me?",
  "One Does Not Connect To Wi-Fi",
  "Shut Up Your Dogs",
  "No Free Wi-Fi Here",
  "Your Wi-Fi Is In Another Castle",
  "Your Bandwidth Are Belong to Us",
  "Password is Password",
  "I'm Under Your Bed",
  "Hell Guest Network",
  "Milk Make The Cookies Wet",
  "Does God Know U Steal Internet?",
  "Funny, It Worked Last Time",
  "I Now Declare You Man and Wi-Fi",
  "We can here you having",
  "Hide Yo Kids Hide Yo WiFi",
  "Prohibited Area",
  "Mom Use This One",
  "Abraham Linksys",
  "Benjamin FrankLAN",
  "Martin Router King",
  "John Wilkes Bluetooth",
  "Pretty Fly for a Wi-Fi",
  "Bill Wi the Science Fi",
  "I Believe Wi Can Fi",
  "Tell My Wi-Fi Love Her",
  "No More Mister Wi-Fi",
  "LAN Solo",
  "The LAN Before Time",
  "Silence of the LANs",
  "House LANister",
  "Winternet Is Coming",
  "Ping’s Landing",
  "The Ping in the North",
  "This LAN Is My LAN",
  "Get Off My LAN",
  "The Promised LAN",
  "The LAN Down Under",
  "FBI Surveillance Van 4",
  "Area 51 Test Site",
  "Drive-By Wi-Fi",
  "Planet Express",
  "Wu Tang LAN",
  "Darude LANstorm",
  "Never Gonna Give You Up",
  "Hide Yo Kids, Hide Yo Wi-Fi",
  "Loading…",
  "Searching…",
  "Sleeping…",
  "Thinking…",
  "VIRUS.EXE",
  "Virus-Infected Wi-Fi",
  "Starbucks Wi-Fi",
  "Text ###-#### for Password",
  "Yell ____ for Password",
  "The Password Is 1234",
  "Free Public Wi-Fi",
  "No Free Wi-Fi Here",
  "Get Your Own Damn Wi-Fi",
  "It Hurts When IP",
  "Dora the Internet Explorer",
  "404 Wi-Fi Unavailable",
  "Porque-Fi",
  "Titanic Syncing",
  "Test Wi-Fi Please Ignore",
  "Drop It Like It’s Hotspot",
  "Life in the Fast LAN",
  "The Creep Next Door",
  "Ye Olde Internet",
  "Really, asshole? Curry again?",
  "My Neighbors Suck",
  "Yo Mama",
  "Yer Baby Is Really Ugly",
  "Turd Burglar",
  "Little Rocket Man",
  "Quit Stealing My Wi-Fi",
  "Slap Me Harder",
  "Pong Lenis",
  "Fat man on 7fl is douche",
  "Other...",
  "Only For Zombies",
  "No Free Wifi for you",
  "NoFreeINternetHereKeepLooking",
  "Rebooting in 5s...",
  "Click above to turn off WiFi",
  "It Hurts When IP"
};
int ssidFunnySize = sizeof(ssidFunny) / maxNameLen; // Number of entries

/*---------------- SSID names to avoid ----------------*/
char ssidNamesToAvoid[][maxNameLen] = {
  "LOCALHOST",
  "ANONYMOUS",
  "AUTHENTICATED USER",
  "BATCH",
  "BUILTIN",
  "CREATOR GROUP",
  "CREATOR GROUP SERVER",
  "CREATOR OWNER",
  "CREATOR OWNER SERVER",
  "DIALUP",
  "DIGEST AUTH",
  "INTERACTIVE",
  "INTERNET",
  "LOCAL",
  "LOCAL SYSTEM",
  "NETWORK",
  "NETWORK SERVICE",
  "NT AUTHORITY",
  "NT DOMAIN",
  "NTLM AUTH",
  "NULL",
  "PROXY",
  "REMOTE INTERACTIVE",
  "RESTRICTED",
  "SCHANNEL AUTH",
  "SELF",
  "SERVER",
  "SERVICE",
  "SYSTEM",
  "TERMINAL SERVER",
  "THIS ORGANIZATION",
  "USERS",
  "WORLD",
  "WPAD",
  "ISTAP"
};
int ssidNamesToAvoidSize = sizeof(ssidNamesToAvoid) / maxNameLen; // Number of entries

/*----- Declaration of Independence of Cyberspace -----*/
char ssidsDoIoC[][maxNameLen] = {
  "001 A Declaration of the",
  "002 Independence of Cyberspace",
  "003 by John Perry Barlow",
  "004 RIP 2018-02-07",
  "005 ***",
  "006 Governments of the",
  "007 Industrial World, you weary",
  "008 giants of flesh and steel,",
  "009 I come from Cyberspace, the",
  "010 new home of Mind. On behalf",
  "011 of the future, I ask you of",
  "012 the past to leave us alone.",
  "013 You are not welcome among",
  "014 us. You have no sovereignty",
  "015 where we gather.","016 ***",
  "017 We have no elected",
  "018 government, nor are we",
  "019 likely to have one, so I",
  "020 address you with no greater",
  "021 authority than that with",
  "022 which liberty itself always",
  "023 speaks. I declare the",
  "024 global social space we are",
  "025 building to be naturally",
  "026 independent of the",
  "027 tyrannies you seek to",
  "028 impose on us. You have no",
  "029 moral right to rule us nor",
  "030 do you possess any methods",
  "031 of enforcement we have true",
  "032 reason to fear.",
  "033 ***",
  "034 Governments derive their",
  "035 just powers from the",
  "036 consent of the governed.",
  "037 You have neither solicited",
  "038 nor received ours. We did",
  "039 not invite you. You do not",
  "040 know us, nor do you know",
  "041 our world. Cyberspace does",
  "042 not lie within your",
  "043 borders. Do not think that",
  "044 you can build it, as though",
  "045 it were a public",
  "046 construction project. You",
  "047 cannot. It is an act of",
  "048 nature and it grows itself",
  "049 through our collective",
  "050 actions.",
  "051 ***","052 You have not engaged in our",
  "053 great and gathering",
  "054 conversation, nor did you",
  "055 create the wealth of our",
  "056 marketplaces. You do not",
  "057 know our culture, our",
  "058 ethics, or the unwritten",
  "059 codes that already provide",
  "060 our society more order than",
  "061 could be obtained by any of",
  "062 your impositions.",
  "063 ***",
  "064 You claim there are",
  "065 problems among us that you",
  "066 need to solve. You use this",
  "067 claim as an excuse to",
  "068 invade our precincts. Many",
  "069 of these problems don't",
  "070 exist. Where there are real",
  "071 conflicts, where there are",
  "072 wrongs, we will identify",
  "073 them and address them by",
  "074 our means. We are forming",
  "075 our own Social Contract.",
  "076 This governance will arise",
  "077 according to the conditions",
  "078 of our world, not yours.",
  "079 Our world is different.",
  "080 ***",
  "081 Cyberspace consists of",
  "082 transactions,",
  "083 relationships, and thought",
  "084 itself, arrayed like a",
  "085 standing wave in the web of",
  "086 our communications. Ours is",
  "087 a world that is both",
  "088 everywhere and nowhere, but",
  "089 it is not where bodies live",
  "090 ***",
  "091 We are creating a world",
  "092 that all may enter without",
  "093 privilege or prejudice",
  "094 accorded by race, economic",
  "095 power, military force, or",
  "096 station of birth.",
  "097 ***",
  "098 We are creating a world",
  "099 where anyone, anywhere may",
  "100 express his or her beliefs,",
  "101 no matter how singular,",
  "102 without fear of being",
  "103 coerced into silence or",
  "104 conformity.",
  "105 ***",
  "106 Your legal concepts of",
  "107 property, expression,",
  "108 identity, movement, and",
  "109 context do not apply to us.",
  "110 They are all based on",
  "111 matter, and there is no",
  "112 matter here.",
  "113 ***",
  "114 Our identities have no",
  "115 bodies, so, unlike you, we",
  "116 cannot obtain order by",
  "117 physical coercion. We",
  "118 believe that from ethics,",
  "119 enlightened self-interest,",
  "120 and the commonweal, our",
  "121 governance will emerge. Our",
  "122 identities may be",
  "123 distributed across many of",
  "124 your jurisdictions. The",
  "125 only law that all our",
  "126 constituent cultures would",
  "127 generally recognize is the",
  "128 Golden Rule. We hope we",
  "129 will be able to build our",
  "130 particular solutions on",
  "131 that basis. But we cannot",
  "132 accept the solutions you",
  "133 are attempting to impose.",
  "134 ***","135 In the United States, you",
  "136 have today created a law,",
  "137 the Telecommunications",
  "138 Reform Act, which",
  "139 repudiates your own",
  "140 Constitution and insults",
  "141 the dreams of Jefferson,",
  "142 Washington, Mill, Madison,",
  "143 DeToqueville, and Brandeis.",
  "144 These dreams must now be",
  "145 born anew in us.",
  "146 ***",
  "147 You are terrified of your",
  "148 own children, since they",
  "149 are natives in a world",
  "150 where you will always be",
  "151 immigrants. Because you",
  "152 fear them, you entrust your",
  "153 bureaucracies with the",
  "154 parental responsibilities",
  "155 you are too cowardly to",
  "156 confront yourselves. In our",
  "157 world, all the sentiments",
  "158 and expressions of",
  "159 humanity, from the debasing",
  "160 to the angelic, are parts",
  "161 of a seamless whole, the",
  "162 global conversation of",
  "163 bits. We cannot separate",
  "164 the air that chokes from",
  "165 the air upon which wings",
  "166 beat.","167 ***",
  "168 In China, Germany, France,",
  "169 Russia, Singapore, Italy",
  "170 and the United States, you",
  "171 are trying to ward off the",
  "172 virus of liberty by",
  "173 erecting guard posts at the",
  "174 frontiers of Cyberspace.",
  "175 These may keep out the",
  "176 contagion for a small time,",
  "177 but they will not work ina",
  "178 world that will soon be",
  "179 blanketed in bit-bearing",
  "180 media.",
  "181 ***",
  "182 Your increasingly obsolete",
  "183 information industries",
  "184 would perpetuate themselves",
  "185 by proposing laws, in",
  "186 America and elsewhere, that",
  "187 claim to own speech itself",
  "188 throughout the world. These",
  "189 laws would declare ideas to",
  "190 be another industrial",
  "191 product, no more noble than",
  "192 pig iron. In our world,",
  "193 whatever the human mind may",
  "194 create can be reproduced",
  "195 and distributed infinitely",
  "196 at no cost. The global",
  "197 conveyance of thought no",
  "198 longer requires your",
  "199 factories to accomplish.",
  "200 ***",
  "201 These increasingly hostile",
  "202 and colonial measures place",
  "203 us in the same position as",
  "204 those previous lovers of",
  "205 freedom and",
  "206 self-determination who had",
  "207 to reject the authorities",
  "208 of distant, uninformed",
  "209 powers. We must declare our",
  "210 virtual selves immune to",
  "211 your sovereignty, even as",
  "212 we continue to consent to",
  "213 your rule over our bodies.",
  "214 We will spread ourselves",
  "215 across the Planet so that",
  "216 no one can arrest our",
  "217 thoughts.",
  "218 ***","219 We will create a",
  "220 civilization of the Mind in",
  "221 Cyberspace. May it be more",
  "222 humane and fair than the",
  "223 world your governments have",
  "224 made before.",
  "225 ***",
  "226 Davos, Switzerland",
  "227 February 8, 1996",
  "228 ***"
};
int ssidsDoIoCSize = sizeof(ssidsDoIoC) / maxNameLen;	// Number of entries

/* ========================================== */
#endif // ifndef SSIDs_h
