#include <iostream>
#include<fstream>
#include<curl/curl.h>
#include<string>
#include<algorithm>
#include<cctype>
#include<map>
#include<cstdlib>
#include<ctime>

void write_function(std::string arr1, std::map<std::string, int>& m)
{

	transform(arr1.begin(), arr1.end(), arr1.begin(), ::tolower);
	if ((arr1 != "about") && (arr1 != "above") && (arr1 != "after") && (arr1 != "again") && (arr1 != "across") && (arr1 != "against") && (arr1 != "all") && (arr1 != "almost") && (arr1 != "alone") && (arr1 != "along") && (arr1 != "also") && (arr1 != "already") && (arr1 != "although") && (arr1 != "always") && (arr1 != "among") && (arr1 != "and") && (arr1 != "an") && (arr1 != "another") && (arr1 != "any") && (arr1 != "anything") && (arr1 != "anybody") && (arr1 != "anyone") && (arr1 != "are") && (arr1 != "area") && (arr1 != "areas") && (arr1 != "around") && (arr1 != "as") && (arr1 != "asked") && (arr1 != "ask") && (arr1 != "asking") && (arr1 != "asks") && (arr1 != "at") && (arr1 != "away") && (arr1 != "back") && (arr1 != "backed") && (arr1 != "backing") && (arr1 != "backs") && (arr1 != "be") && (arr1 != "became") && (arr1 != "because") && (arr1 != "become") && (arr1 != "becomes") && (arr1 != "been") && (arr1 != "began") && (arr1 != "before") && (arr1 != "behind") && (arr1 != "being") && (arr1 != "beings") && (arr1 != "best") && (arr1 != "better") && (arr1 != "between") && (arr1 != "big") && (arr1 != "both") && (arr1 != "but") && (arr1 != "by") && (arr1 != "came") && (arr1 != "can") && (arr1 != "cannot") && (arr1 != "case") && (arr1 != "cases") && (arr1 != "certain") && (arr1 != "certainly") && (arr1 != "clear") && (arr1 != "clearly") && (arr1 != "come") && (arr1 != "could") && (arr1 != "did") && (arr1 != "differ") && (arr1 != "different") && (arr1 != "differently") && (arr1 != "do") && (arr1 != "does") && (arr1 != "done") && (arr1 != "down") && (arr1 != "downed") && (arr1 != "downing") && (arr1 != "downs") && (arr1 != "during") && (arr1 != "each") && (arr1 != "early") && (arr1 != "either") && (arr1 != "end") && (arr1 != "ended") && (arr1 != "enough") && (arr1 != "even") && (arr1 != "evenly") && (arr1 != "ever") && (arr1 != "every") && (arr1 != "everybody") && (arr1 != "everything") && (arr1 != "everyone") && (arr1 != "everywhere") && (arr1 != "face") && (arr1 != "faces") && (arr1 != "fact") && (arr1 != "facts") && (arr1 != "far") && (arr1 != "felt") && (arr1 != "few") && (arr1 != "find") && (arr1 != "finds") && (arr1 != "first") && (arr1 != "for") && (arr1 != "four") && (arr1 != "from") && (arr1 != "fully") && (arr1 != "full") && (arr1 != "further") && (arr1 != "furthered") && (arr1 != "furthering") && (arr1 != "furthers") && (arr1 != "gave") && (arr1 != "general") && (arr1 != "generally") && (arr1 != "get") && (arr1 != "gets") && (arr1 != "give") && (arr1 != "given") && (arr1 != "gives") && (arr1 != "go") && (arr1 != "going") && (arr1 != "good") && (arr1 != "goods") && (arr1 != "got") && (arr1 != "great") && (arr1 != "greater") && (arr1 != "greatest") && (arr1 != "group") && (arr1 != "grouped") && (arr1 != "grouping") && (arr1 != "groups") && (arr1 != "had") && (arr1 != "has") && (arr1 != "have") && (arr1 != "having") && (arr1 != "he") && (arr1 != "her") && (arr1 != "here") && (arr1 != "herself") && (arr1 != "high") && (arr1 != "higher") && (arr1 != "highest") && (arr1 != "him") && (arr1 != "himself") && (arr1 != "his") && (arr1 != "how") && (arr1 != "however") && (arr1 != "if") && (arr1 != "important") && (arr1 != "in") && (arr1 != "interest") && (arr1 != "interested") && (arr1 != "interesting") && (arr1 != "interests") && (arr1 != "into") && (arr1 != "is") && (arr1 != "it") && (arr1 != "its") && (arr1 != "itself") && (arr1 != "just") && (arr1 != "keep") && (arr1 != "keeps") && (arr1 != "kind") && (arr1 != "knew") && (arr1 != "know") && (arr1 != "known") && (arr1 != "knows") && (arr1 != "large") && (arr1 != "largely") && (arr1 != "last") && (arr1 != "later") && (arr1 != "latest") && (arr1 != "least") && (arr1 != "less") && (arr1 != "let") && (arr1 != "lets") && (arr1 != "like") && (arr1 != "likely") && (arr1 != "long") && (arr1 != "longer") && (arr1 != "longest") && (arr1 != "made") && (arr1 != "make") && (arr1 != "making") && (arr1 != "man") && (arr1 != "many") && (arr1 != "may") && (arr1 != "me") && (arr1 != "member") && (arr1 != "members") && (arr1 != "men") && (arr1 != "might") && (arr1 != "more") && (arr1 != "most") && (arr1 != "mostly") && (arr1 != "mr") && (arr1 != "mrs") && (arr1 != "much") && (arr1 != "must") && (arr1 != "my") && (arr1 != "myself") && (arr1 != "necessary") && (arr1 != "need") && (arr1 != "needed") && (arr1 != "needing") && (arr1 != "needs") && (arr1 != "never") && (arr1 != "new") && (arr1 != "newer") && (arr1 != "newest") && (arr1 != "next") && (arr1 != "no") && (arr1 != "nobody") && (arr1 != "non") && (arr1 != "noone") && (arr1 != "not") && (arr1 != "nothing") && (arr1 != "now") && (arr1 != "nowhere") && (arr1 != "number") && (arr1 != "numbers") && (arr1 != "of") && (arr1 != "off") && (arr1 != "often") && (arr1 != "old") && (arr1 != "older") && (arr1 != "oldest") && (arr1 != "on") && (arr1 != "once") && (arr1 != "one") && (arr1 != "only") && (arr1 != "open") && (arr1 != "opened") && (arr1 != "opening") && (arr1 != "opens") && (arr1 != "or") && (arr1 != "order") && (arr1 != "ordered") && (arr1 != "ordering") && (arr1 != "orders") && (arr1 != "other") && (arr1 != "others") && (arr1 != "our") && (arr1 != "out") && (arr1 != "over") && (arr1 != "part") && (arr1 != "parted") && (arr1 != "parting") && (arr1 != "parts") && (arr1 != "per") && (arr1 != "perhaps") && (arr1 != "place") && (arr1 != "places") && (arr1 != "point") && (arr1 != "pointed") && (arr1 != "pointing") && (arr1 != "points") && (arr1 != "possible") && (arr1 != "present") && (arr1 != "presented") && (arr1 != "presenting") && (arr1 != "presents") && (arr1 != "problem") && (arr1 != "problems") && (arr1 != "put") && (arr1 != "puts") && (arr1 != "quite") && (arr1 != "rather") && (arr1 != "really") && (arr1 != "right") && (arr1 != "room") && (arr1 != "rooms") && (arr1 != "said") && (arr1 != "same") && (arr1 != "saw") && (arr1 != "say") && (arr1 != "says") && (arr1 != "second") && (arr1 != "seconds") && (arr1 != "see") && (arr1 != "seems") && (arr1 != "seemed") && (arr1 != "seeming") && (arr1 != "sees") && (arr1 != "several") && (arr1 != "shall") && (arr1 != "she") && (arr1 != "should") && (arr1 != "show") && (arr1 != "showed") && (arr1 != "showing") && (arr1 != "shows") && (arr1 != "side") && (arr1 != "sides") && (arr1 != "since") && (arr1 != "small") && (arr1 != "smaller") && (arr1 != "smallest") && (arr1 != "so") && (arr1 != "some") && (arr1 != "somebody") && (arr1 != "someone") && (arr1 != "something") && (arr1 != "somewhere") && (arr1 != "state") && (arr1 != "states") && (arr1 != "still") && (arr1 != "such") && (arr1 != "sure") && (arr1 != "take") && (arr1 != "taken") && (arr1 != "than") && (arr1 != "the") && (arr1 != "their") && (arr1 != "them") && (arr1 != "then") && (arr1 != "there") && (arr1 != "therefore") && (arr1 != "these") && (arr1 != "they") && (arr1 != "thing") && (arr1 != "things") && (arr1 != "think") && (arr1 != "thinks") && (arr1 != "this") && (arr1 != "those") && (arr1 != "though") && (arr1 != "thought") && (arr1 != "thoughts") && (arr1 != "three") && (arr1 != "through") && (arr1 != "thus") && (arr1 != "to") && (arr1 != "today") && (arr1 != "together") && (arr1 != "too") && (arr1 != "took") && (arr1 != "toward") && (arr1 != "turn") && (arr1 != "turned") && (arr1 != "turning") && (arr1 != "turns") && (arr1 != "two") && (arr1 != "under") && (arr1 != "until") && (arr1 != "up") && (arr1 != "upon") && (arr1 != "us") && (arr1 != "use") && (arr1 != "used") && (arr1 != "uses") && (arr1 != "very") && (arr1 != "want") && (arr1 != "wanted") && (arr1 != "wanting") && (arr1 != "wants") && (arr1 != "was") && (arr1 != "way") && (arr1 != "ways") && (arr1 != "we") && (arr1 != "well") && (arr1 != "wells") && (arr1 != "went") && (arr1 != "were") && (arr1 != "what") && (arr1 != "when") && (arr1 != "where") && (arr1 != "whether") && (arr1 != "which") && (arr1 != "while") && (arr1 != "who") && (arr1 != "whole") && (arr1 != "whose") && (arr1 != "why") && (arr1 != "will") && (arr1 != "with") && (arr1 != "within") && (arr1 != "without") && (arr1 != "work") && (arr1 != "worked") && (arr1 != "working") && (arr1 != "works") && (arr1 != "would") && (arr1 != "year") && (arr1 != "years") && (arr1 != "yet") && (arr1 != "you") && (arr1 != "young") && (arr1 != "younger") && (arr1 != "youngest") && (arr1 != "your") && (arr1 != "yours"))
	{
		if (arr1.length() > 2)
			m[arr1]++;
	}
}


size_t write_data_on_file(void* ptr, size_t size_of_data, size_t number_of_element, std::fstream* file)
{
	size_t total_size = size_of_data * number_of_element;
	file->write((char*)ptr, total_size);
	return total_size;
}

int main(int argc, char* argv[])
{
	std::string url;
	if (argc == 2)
	{
		url = argv[1];
	}
	else
	{
		std::cout << "Enter URL to download content = ";
		getline(std::cin, url);
	}

	CURL* handle;

	handle = curl_easy_init();
	if (!handle)
	{
		std::cout << "Handle could not be initialized run program again \n";
		return 0;
	}
	std::fstream file;
	file.open("F:\\downdloads.dat", std::ios::binary | std::ios::out);
	if (!file.is_open())
	{
		std::cout << "File could not be opened to write downloaded data \n";
		return 0;
	}

	curl_easy_setopt(handle, CURLOPT_URL, url.data());
	curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_data_on_file);
	curl_easy_setopt(handle, CURLOPT_WRITEDATA, &file);
	curl_easy_setopt(handle, CURLOPT_FOLLOWLOCATION, 1L);
	curl_easy_setopt(handle, CURLOPT_TIMEOUT, 60L);
	curl_easy_setopt(handle, CURLOPT_USERPWD, "muhammadtayyab:pass@1qau"); // some website does not allow to take data without log in to that site so this password and used name will automatically be used to login to that site to download the content
	curl_easy_setopt(handle, CURLOPT_LOW_SPEED_LIMIT, 51200L);//i have set minnimum acceptable speed upto 50kb per second
	curl_easy_setopt(handle, CURLOPT_LOW_SPEED_TIME, 5L);  //CURL ABBORTS IF SPEED IS LESS THAN 50KB PER SECOND FOR 5 SECONDS

	CURLcode results = curl_easy_perform(handle);
	if (results != CURLE_OK)
	{
		std::cout << "Download Failled " << curl_easy_strerror(results) << std::endl;
		return 0;
	}

	std::cout << "Download was successfull \n";
	file.close();
	curl_easy_cleanup(handle);
	//after downloading is done we go for further process 

	std::map<std::string, int> m;
	std::map<std::string, int>::iterator it;
	file.open("F:\\downdloads.dat", std::ios::in);
	if (!file.is_open())
	{
		std::cout << "File cannot be opened to read HTML contents from it\n";
		return 0;
	}
	char ch;
	std::string arr1;
	while (file.get(ch))
	{


		if (ch == '<')
		{
			if (!arr1.empty()) //this will separate words from tags as <a>Google</a><a>Search</a> if this wirte does not exists here it would count as "GooleSeach" as single word but for now it will count "Google" "search" separatly
			{
				write_function(arr1, m);
				arr1.clear();
			}
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
			bool f2 = (s1[0] != '/' && s1.find("style") != std::string::npos);

			if (f1 || f2)
			{
				std::string temp;
				while (file.get(ch))
				{
					temp += ch;
					if (temp.size() > 11)
					{
						temp.erase(0, temp.size() - 9);
					}
					transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

					if ((temp.find("</script") != std::string::npos) || (temp.find("</style>") != std::string::npos))
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
				if (std::isalpha(static_cast<unsigned char>(ch)))//this cassting is done because if we have signed char than isalpha function throws an exception to go on safe side this casting is done here
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
	//Now everthing is ready to write into html file and i am further proceeding to write in html file 
	std::srand(time(NULL));
	std::fstream htmlfile;
	htmlfile.open("F:\\world_cloud_generator.html", std::ios::out);
	if (!htmlfile.is_open())
	{
		std::cout << "HTML file could not be opened to write data into it \n";
		return 0;
	}
	htmlfile << "<!DOCTYPE html>" << std::endl;
	htmlfile << "<html lang ='en'>" << std::endl;
	htmlfile << "<head>" << std::endl;
	htmlfile << "<meta charset ='UTF-8'>" << std::endl;
	htmlfile << "<meta name ='viewport' content='width=device-width,initial-scale=1.0'>" << std::endl;
	htmlfile << "<title> Word cloud generator</title>" << std::endl;
	htmlfile << "</head>" << std::endl;
	htmlfile << "<style>" << std::endl;
	htmlfile << ".login-btn{ background-color:aquamarine; \nborder-radius:40%; border:none;\n height:70px;\n width:120px;\n font-size:18px; \n cursor:pointer; \n margin-top:10px;\n margin-left:20px;\n font-style:italic;}" << std::endl;
	htmlfile << ".login-btn:hover {\n color:brown;\n background-color:white;\n border-color:darkblue;font-family:Impact,Haettenschweiler,'Arial Narrow Bold',sans-serif;}\n</style>" << std::endl;
	htmlfile << "<body style='background-color:azure;'>" << std::endl;

	htmlfile << "<div style='height:100px;background-color:aquamarine; border:5px solid aqua; display:flex;top:0px;'>" << std::endl;
	htmlfile << "<a href='https://www.qau.edu.pk' target ='_blank'> <img style='height: 90px; width: 90px;' src='QAU-Logo.png'> </a>" << std::endl;
	htmlfile << "<button class = 'login-btn' onclick = \"window.open('https://qau.edu.pk/','_blank')\">Home</button>" << std::endl;
	htmlfile << "<button class ='login-btn' onclick = \"window.open('https://ugadmissions.qau.edu.pk/oas/app/signin.aspx','_blank')\">Log in </button>" << std::endl;
	htmlfile << "<button class ='login-btn' onclick =\"window.open('https://ugadmissions.qau.edu.pk/oas/app/register.aspx','_blank')\">Apply Now</button>" << std::endl;
	htmlfile << "<button class ='login-btn' onclick = \"window.open('https://lib.qau.edu.pk/','_blank')\">Library</button>" << std::endl;
	htmlfile << "<button class ='login-btn' onclick = \"window.open('https://ugadmissions.qau.edu.pk/hms/StudentHome.html','_blank')\">Hostel Apply</button>" << std::endl;
	htmlfile << "<button class ='login-btn' onclick = \"window.open('https://qau.edu.pk/#','_blank') \">CMS</button>" << std::endl;
	htmlfile << "<button class ='login-btn' style =\"width:170px;\" onclick =\"window.open('https://qau.edu.pk/life-at-campus/','_blank')\">Life-at-campus</button>" << std::endl;
	htmlfile << "<button class ='login-btn' style =\"width:170px;\" onclick =\"window.open('https://jobs.qau.edu.pk/','_blank')\">Jobs</button>" << std::endl;
	htmlfile << "</div>" << std::endl;
	htmlfile << "<div style ='height: 110px; margin-top: 50px;'>" << std::endl;
	htmlfile << "<h2 style = 'margin-left: 350px; color:black;font-size:30px;'>Quaid-E-Azam University Islamabad, Pakistan <br></h1>" << std::endl;
	htmlfile << "<h2 style ='color: black;margin-left: 350px; font-style: italic;'>Word cloud generated by:  TAYYAB RAFIQ MALIK</h2>" << std::endl;
	htmlfile << "</div>" << std::endl;
	it = m.begin();
	htmlfile << "<h1 style='color:black; margin-left:350px;'>Word Cloud Is Shown Below </h1>" << std::endl;
	htmlfile << "<div style='position:relative; height:800px; width:1000px;border-radius:20%; margin-left:auto;margin-right:auto;display:flex-box;padding:20px;border-radius:10%;overflow:hidden;word-wrap:break-word; font:bold; ' >" << std::endl;
	while (it != m.end())
	{
		int rotation = (rand() % 2 == 0) ? 0 : (rand() % 21 - 20); //this only generated value between -20 and 20 for rotation 
		int offset = (rand() % 2 == 0) ? 0 : (rand() % 11 - 10); //this only generated value between -10 to 10 for vertical shift of words 

		//Use of AI for how to position words in cloud shape
		int left = rand() % 650;    //for position        
		int top = rand() % 500; //for position in coordinates 
		if (it->second == 1)
		{
			htmlfile << "<span style='transform:rotate(" << rotation << "deg); white-space:nowrap;text-shadow:1px 1px 2px rgba(0,0,0,0.15);position:absolute;left:" << left << "px;top:" << top << "px; padding:4px 8px; color:blueviolet; margin:2px; font - size:19px; '>" << it->first << "</span>";
		}
		else if (it->second == 2)
		{
			htmlfile << "<span style=' position:absolute;white-space:nowrap;left:" << left << "px;top:" << top << "px; padding:4px 8px;text-shadow:1px 1px 2px rgba(0,0,0,0.15); margin:2px; color:darkgreen;transform:rotate(" << rotation << "deg); font-size:23px;'>" << it->first << "</span>";
		}
		else if (it->second == 3)
		{
			htmlfile << "<span style=' position:absolute;white-space:nowrap;left:" << left << "px;top:" << top << "px; padding:4px 8px;text-shadow:1px 1px 2px rgba(0,0,0,0.15); margin:2px; color:chartreuse;transform:rotate(" << rotation << "deg); font-size:27px;'>" << it->first << "</span>";
		}
		else if (it->second == 4)
		{
			htmlfile << "<span style=' position:absolute;white-space:nowrap;left:" << left << "px;top:" << top << "px; padding:4px 8px;text-shadow:1px 1px 2px rgba(0,0,0,0.15); margin:2px; color:crimson; transform:rotate(" << rotation << "deg); font-size:31px;'>" << it->first << "</span>";
		}
		else if (it->second == 5)
		{
			htmlfile << "<span style='  position:absolute;white-space:nowrap;left:" << left << "px;top:" << top << "px; padding:4px 8px;text-shadow:1px 1px 2px rgba(0,0,0,0.15); margin:2px; color:darkblue;transform:rotate(" << rotation << "deg); font-size:35px;'>" << it->first << "</span>";
		}
		else if (it->second == 6)
		{
			htmlfile << "<span style=' position:absolute;white-space:nowrap;left:" << left << "px;top:" << top << "px; padding:4px 8px; margin:2px;text-shadow:1px 1px 2px rgba(0,0,0,0.15); color:rosybrown;transform:rotate(" << rotation << "deg); font-size:39px;'>" << it->first << "</span>";
		}
		else if (it->second == 7)
		{
			htmlfile << "<span style=' position:absolute;white-space:nowrap;left:" << left << "px;top:" << top << "px; padding:4px 8px; margin:2px;text-shadow:1px 1px 2px rgba(0,0,0,0.15); color:gold;transform:rotate(" << rotation << "deg); font-size:43px;'>" << it->first << "</span>";
		}
		else if (it->second == 8)
		{
			htmlfile << "<span style=' position:absolute;white-space:nowrap;left:" << left << "px;top:" << top << "px; padding:4px 8px; margin:2px;text-shadow:1px 1px 2px rgba(0,0,0,0.15); color:black;transform:rotate(" << rotation << "deg); font-size:47px;'>" << it->first << "</span>";
		}
		else
		{
			htmlfile << "<span style=' position:absolute;white-space:nowrap;left:" << left << "px;top:" << top << "px; padding:4px 8px; margin:2px;text-shadow:1px 1px 2px rgba(0,0,0,0.15); color:yellowgreen;transform:rotate(" << rotation << "deg);  font-size:" << (it->second * 3) << "px; '>" << it->first << "</span>";
		}

		++it;
	}
	htmlfile << "</div>";
	htmlfile << "</br>\n</br>\n</br>\n</br>\n</br>" << std::endl;
	htmlfile << "<footer style='border:1px solid black; height:160px;'> " << std::endl;
	htmlfile << "<a href='https://www.linkedin.com/in/muhammad-tayyab-a54554364?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app' target='_blank' style='display:inline-block; vertical-align:top; margin-left:100px;'><img style='height:20px;width:20px;padding-left:50px;padding-top:35px;' src='https://cdn-icons-png.flaticon.com/512/174/174857.png'></a>" << std::endl;

	htmlfile << "" << std::endl;
	htmlfile << "<span style='display:inline-block; vertical-align:top; font-size:22px; padding-left:10px; padding-top:35px;'>Muhammad Tayyab</span>" << std::endl;

	htmlfile << "<span style='display:inline-block; vertical-align:top; margin-left:100px;'><img style='height:20px;width:20px;padding-left:50px;padding-top:35px;' src='https://logo.svgcdn.com/logos/google-gmail.png' alt='Gmail'></span>" << std::endl;
	htmlfile << "<span style='display:inline-block; vertical-align:top; font-size:22px; padding-left:10px; padding-top:35px;'>muhammadtayyab7541@gmail.com</span>" << std::endl;

	htmlfile << "<a href='https://github.com/tayyab7541/C-projects' target='_blank' style='display:inline-block; vertical-align:top; margin-left:100px;'><img style='height:50px;width:50px;padding-left:50px; padding-top:20px;' src='data:image/png;base64,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' alt='GitHub'></a>" << std::endl;

	htmlfile << "</footer>" << std::endl;
	htmlfile << "</body>";
	htmlfile << "</html>" << std::endl;
	htmlfile.close();

}
