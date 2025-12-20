#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<map>

void write_function(std::string arr1, std::map<std::string, int>& m)
{

	transform(arr1.begin(), arr1.end(), arr1.begin(), ::tolower);
	if ((arr1 != "about") && (arr1 != "above") && (arr1 != "after") && (arr1 != "again") && (arr1 != "across") && (arr1 != "against") && (arr1 != "all") && (arr1 != "almost") && (arr1 != "alone") && (arr1 != "along") && (arr1 != "also") && (arr1 != "already") && (arr1 != "although") && (arr1 != "always") && (arr1 != "among") && (arr1 != "and") && (arr1 != "an") && (arr1 != "another") && (arr1 != "any") && (arr1 != "anything") && (arr1 != "anybody") && (arr1 != "anyone") && (arr1 != "are") && (arr1 != "area") && (arr1 != "areas") && (arr1 != "around") && (arr1 != "as") && (arr1 != "asked") && (arr1 != "ask") && (arr1 != "asking") && (arr1 != "asks") && (arr1 != "at") && (arr1 != "away") && (arr1 != "back") && (arr1 != "backed") && (arr1 != "backing") && (arr1 != "backs") && (arr1 != "be") && (arr1 != "became") && (arr1 != "because") && (arr1 != "become") && (arr1 != "becomes") && (arr1 != "been") && (arr1 != "began") && (arr1 != "before") && (arr1 != "behind") && (arr1 != "being") && (arr1 != "beings") && (arr1 != "best") && (arr1 != "better") && (arr1 != "between") && (arr1 != "big") && (arr1 != "both") && (arr1 != "but") && (arr1 != "by") && (arr1 != "came") && (arr1 != "can") && (arr1 != "cannot") && (arr1 != "case") && (arr1 != "cases") && (arr1 != "certain") && (arr1 != "certainly") && (arr1 != "clear") && (arr1 != "clearly") && (arr1 != "come") && (arr1 != "could") && (arr1 != "did") && (arr1 != "differ") && (arr1 != "different") && (arr1 != "differently") && (arr1 != "do") && (arr1 != "does") && (arr1 != "done") && (arr1 != "down") && (arr1 != "downed") && (arr1 != "downing") && (arr1 != "downs") && (arr1 != "during") && (arr1 != "each") && (arr1 != "early") && (arr1 != "either") && (arr1 != "end") && (arr1 != "ended") && (arr1 != "enough") && (arr1 != "even") && (arr1 != "evenly") && (arr1 != "ever") && (arr1 != "every") && (arr1 != "everybody") && (arr1 != "everything") && (arr1 != "everyone") && (arr1 != "everywhere") && (arr1 != "face") && (arr1 != "faces") && (arr1 != "fact") && (arr1 != "facts") && (arr1 != "far") && (arr1 != "felt") && (arr1 != "few") && (arr1 != "find") && (arr1 != "finds") && (arr1 != "first") && (arr1 != "for") && (arr1 != "four") && (arr1 != "from") && (arr1 != "fully") && (arr1 != "full") && (arr1 != "further") && (arr1 != "furthered") && (arr1 != "furthering") && (arr1 != "furthers") && (arr1 != "gave") && (arr1 != "general") && (arr1 != "generally") && (arr1 != "get") && (arr1 != "gets") && (arr1 != "give") && (arr1 != "given") && (arr1 != "gives") && (arr1 != "go") && (arr1 != "going") && (arr1 != "good") && (arr1 != "goods") && (arr1 != "got") && (arr1 != "great") && (arr1 != "greater") && (arr1 != "greatest") && (arr1 != "group") && (arr1 != "grouped") && (arr1 != "grouping") && (arr1 != "groups") && (arr1 != "had") && (arr1 != "has") && (arr1 != "have") && (arr1 != "having") && (arr1 != "he") && (arr1 != "her") && (arr1 != "here") && (arr1 != "herself") && (arr1 != "high") && (arr1 != "higher") && (arr1 != "highest") && (arr1 != "him") && (arr1 != "himself") && (arr1 != "his") && (arr1 != "how") && (arr1 != "however") && (arr1 != "if") && (arr1 != "important") && (arr1 != "in") && (arr1 != "interest") && (arr1 != "interested") && (arr1 != "interesting") && (arr1 != "interests") && (arr1 != "into") && (arr1 != "is") && (arr1 != "it") && (arr1 != "its") && (arr1 != "itself") && (arr1 != "just") && (arr1 != "keep") && (arr1 != "keeps") && (arr1 != "kind") && (arr1 != "knew") && (arr1 != "know") && (arr1 != "known") && (arr1 != "knows") && (arr1 != "large") && (arr1 != "largely") && (arr1 != "last") && (arr1 != "later") && (arr1 != "latest") && (arr1 != "least") && (arr1 != "less") && (arr1 != "let") && (arr1 != "lets") && (arr1 != "like") && (arr1 != "likely") && (arr1 != "long") && (arr1 != "longer") && (arr1 != "longest") && (arr1 != "made") && (arr1 != "make") && (arr1 != "making") && (arr1 != "man") && (arr1 != "many") && (arr1 != "may") && (arr1 != "me") && (arr1 != "member") && (arr1 != "members") && (arr1 != "men") && (arr1 != "might") && (arr1 != "more") && (arr1 != "most") && (arr1 != "mostly") && (arr1 != "mr") && (arr1 != "mrs") && (arr1 != "much") && (arr1 != "must") && (arr1 != "my") && (arr1 != "myself") && (arr1 != "necessary") && (arr1 != "need") && (arr1 != "needed") && (arr1 != "needing") && (arr1 != "needs") && (arr1 != "never") && (arr1 != "new") && (arr1 != "newer") && (arr1 != "newest") && (arr1 != "next") && (arr1 != "no") && (arr1 != "nobody") && (arr1 != "non") && (arr1 != "noone") && (arr1 != "not") && (arr1 != "nothing") && (arr1 != "now") && (arr1 != "nowhere") && (arr1 != "number") && (arr1 != "numbers") && (arr1 != "of") && (arr1 != "off") && (arr1 != "often") && (arr1 != "old") && (arr1 != "older") && (arr1 != "oldest") && (arr1 != "on") && (arr1 != "once") && (arr1 != "one") && (arr1 != "only") && (arr1 != "open") && (arr1 != "opened") && (arr1 != "opening") && (arr1 != "opens") && (arr1 != "or") && (arr1 != "order") && (arr1 != "ordered") && (arr1 != "ordering") && (arr1 != "orders") && (arr1 != "other") && (arr1 != "others") && (arr1 != "our") && (arr1 != "out") && (arr1 != "over") && (arr1 != "part") && (arr1 != "parted") && (arr1 != "parting") && (arr1 != "parts") && (arr1 != "per") && (arr1 != "perhaps") && (arr1 != "place") && (arr1 != "places") && (arr1 != "point") && (arr1 != "pointed") && (arr1 != "pointing") && (arr1 != "points") && (arr1 != "possible") && (arr1 != "present") && (arr1 != "presented") && (arr1 != "presenting") && (arr1 != "presents") && (arr1 != "problem") && (arr1 != "problems") && (arr1 != "put") && (arr1 != "puts") && (arr1 != "quite") && (arr1 != "rather") && (arr1 != "really") && (arr1 != "right") && (arr1 != "room") && (arr1 != "rooms") && (arr1 != "said") && (arr1 != "same") && (arr1 != "saw") && (arr1 != "say") && (arr1 != "says") && (arr1 != "second") && (arr1 != "seconds") && (arr1 != "see") && (arr1 != "seems") && (arr1 != "seemed") && (arr1 != "seeming") && (arr1 != "sees") && (arr1 != "several") && (arr1 != "shall") && (arr1 != "she") && (arr1 != "should") && (arr1 != "show") && (arr1 != "showed") && (arr1 != "showing") && (arr1 != "shows") && (arr1 != "side") && (arr1 != "sides") && (arr1 != "since") && (arr1 != "small") && (arr1 != "smaller") && (arr1 != "smallest") && (arr1 != "so") && (arr1 != "some") && (arr1 != "somebody") && (arr1 != "someone") && (arr1 != "something") && (arr1 != "somewhere") && (arr1 != "state") && (arr1 != "states") && (arr1 != "still") && (arr1 != "such") && (arr1 != "sure") && (arr1 != "take") && (arr1 != "taken") && (arr1 != "than") && (arr1 != "the") && (arr1 != "their") && (arr1 != "them") && (arr1 != "then") && (arr1 != "there") && (arr1 != "therefore") && (arr1 != "these") && (arr1 != "they") && (arr1 != "thing") && (arr1 != "things") && (arr1 != "think") && (arr1 != "thinks") && (arr1 != "this") && (arr1 != "those") && (arr1 != "though") && (arr1 != "thought") && (arr1 != "thoughts") && (arr1 != "three") && (arr1 != "through") && (arr1 != "thus") && (arr1 != "to") && (arr1 != "today") && (arr1 != "together") && (arr1 != "too") && (arr1 != "took") && (arr1 != "toward") && (arr1 != "turn") && (arr1 != "turned") && (arr1 != "turning") && (arr1 != "turns") && (arr1 != "two") && (arr1 != "under") && (arr1 != "until") && (arr1 != "up") && (arr1 != "upon") && (arr1 != "us") && (arr1 != "use") && (arr1 != "used") && (arr1 != "uses") && (arr1 != "very") && (arr1 != "want") && (arr1 != "wanted") && (arr1 != "wanting") && (arr1 != "wants") && (arr1 != "was") && (arr1 != "way") && (arr1 != "ways") && (arr1 != "we") && (arr1 != "well") && (arr1 != "wells") && (arr1 != "went") && (arr1 != "were") && (arr1 != "what") && (arr1 != "when") && (arr1 != "where") && (arr1 != "whether") && (arr1 != "which") && (arr1 != "while") && (arr1 != "who") && (arr1 != "whole") && (arr1 != "whose") && (arr1 != "why") && (arr1 != "will") && (arr1 != "with") && (arr1 != "within") && (arr1 != "without") && (arr1 != "work") && (arr1 != "worked") && (arr1 != "working") && (arr1 != "works") && (arr1 != "would") && (arr1 != "year") && (arr1 != "years") && (arr1 != "yet") && (arr1 != "you") && (arr1 != "young") && (arr1 != "younger") && (arr1 != "youngest") && (arr1 != "your") && (arr1 != "yours"))
	{
		if (arr1.length() > 2)
			m[arr1]++;
	}
}

int main(int argc, char** argv)
{
	std::fstream file;
	std::map<std::string, int> m;
	std::map<std::string, int>::iterator it;
	std::string file_name;

	if (argc <=1)
	{
		std::cout << "Enter path of text file = ";
		std::getline(std::cin, file_name);
	}
	else
	{
		file_name = argv[1];

	}
	file.open(file_name, std::ios::in);

	if (!file.is_open())
	{
		std::cout << "There is error in path given and file cannot be opened\n";
		return 0;
	}
	char ch;
	std::string arr1;
	while (file.get(ch))
	{
		

	 if (ch == '<')
		{
		 std::string s1;
		 while (file.get(ch))
		 {
			 if (ch == '>')
			 {
				 break;
			 }
			 else
				 s1 += ch;

		 }

		 transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		 if (s1.empty())
		 {
			 break;

		 }
		 bool f1 = (s1[0] != '/' && s1.find("script") != std::string::npos);
		 bool f2 = (s1[0] != '/' && s1.find("style") !=std::string::npos);

		 if (f1 || f2)
		 {
			 std::string temp;
			 while (file.get(ch))
			 {
				 temp += ch;
				 if (temp.size() > 11)
				 {
					 temp.erase(0,temp.size() - 9);
				 }
				 transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

				 if ((temp.find("</script") !=std::string::npos) || (temp.find("</style>") != std::string::npos))
					 break;
			 }
		 }
		 
	}
		else if (ch == '.' || ch == ',' || ch == ';' || ch == ':' || ch == '!' || ch == '?' || ch == '"' || ch == '`' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '_' || ch == '/' || ch == '+' || ch == '%' || ch == '*' || ch == '~' || ch == '=' || ch == '@' || ch == '#' || ch == '$' || ch == '&')
		{
		 if (!arr1.empty())
		 {
			 write_function(arr1, m);
			 arr1.clear();
		 }
			continue;
		}
		else
		{
			if (ch != ' ')
			{
				if (isalpha(ch))
				{
					arr1 += ch;
				}
			}
			else
			{
				if (!arr1.empty())
				{
					write_function(arr1, m);
					arr1.clear();

				}
			}
		}
	}
	if (!arr1.empty())  //this is for last word in file 
	{

		write_function(arr1, m);
	}

	file.close();

	it = m.begin();
	while (it != m.end())
	{
			std::cout << it->first << "\t" << it->second << std::endl;
		
		++it;
	}

}
