#include <bits/stdc++.h>
using namespace std;

// bool validPalindrome(string s)
// {
//     int startIt = 0, endIt = s.size() - 1, removedCount = 0;
//     while (startIt < endIt)
//     {
//         if (s[startIt] != s[endIt])
//         {
//             if (removedCount > 0)
//             {
//                 return false;
//             }
//             if (s[startIt + 1] == s[endIt])
//             {
//                 if ((startIt + 2 < endIt - 1))
//                 {
//                     if (s[startIt + 2] == s[endIt - 1])
//                     {
//                         startIt++;
//                     }
//                 }
//                 else
//                 {
//                     startIt++;
//                 }
//             }
//             else if (s[startIt] == s[endIt - 1] || (startIt + 1 < endIt - 2 && s[startIt + 1] == s[endIt - 2]))
//             {
//                 endIt--;
//             }
//             else
//             {
//                 return false;
//             }
//             removedCount++;
//             cout << s[startIt] << "  " << s[endIt] << "  " << removedCount << endl;
//         }
//         else
//         {
//             cout << s[startIt] << "  " << s[endIt] << endl;
//             startIt++;
//             endIt--;
//         }
//     }
//     return true;
// }

bool validHelper(string s, int startIt, int endIt)
{
    while (startIt < endIt)
    {
        if (s[startIt] != s[endIt])
        {
            return false;
        }
        startIt++;
        endIt--;
    }
    return true;
}

bool validPalindrome(string s)
{
    int startIt = 0, endIt = s.size() - 1, removedCount = 0;
    while (startIt < endIt)
    {
        if (s[startIt] != s[endIt])
        {
            return validHelper(s, startIt + 1, endIt) || validHelper(s, startIt, endIt - 1);
        }
        startIt++;
        endIt--;
    }
    return true;
}

// bool validPalindrome(string s)
// {
//     int startIt = 0, endIt = s.size() - 1, removedCount = 0;
//     while (startIt < endIt)
//     {
//         if (s[startIt] != s[endIt])
//         {
//             if (removedCount > 0)
//             {
//                 return false;
//             }
//             if (s[startIt + 1] == s[endIt])
//             {
//                 if ((startIt + 2) < (endIt - 1))
//                 {
//                     if (s[startIt + 2] == s[endIt - 1])
//                     {
//                         startIt++;
//                         removedCount++;

//                         continue;
//                     }
//                 }
//                 else
//                 {
//                     startIt++;
//                     removedCount++;

//                     continue;
//                 }
//             }
//             if (s[startIt] == s[endIt - 1])
//             {
//                 if ((startIt + 1) < (endIt - 2))
//                 {
//                     if (s[startIt + 1] == s[endIt - 2])
//                     {
//                         endIt--;
//                         removedCount++;

//                         continue;
//                     }
//                 }
//                 else
//                 {
//                     endIt--;
//                     removedCount++;

//                     continue;
//                 }
//             }

//             removedCount++;
//             // cout << s[startIt] << "  " << s[endIt] << "  " << removedCount << endl;
//             return false;
//         }
//         else
//         {
//             // cout << s[startIt] << "  " << s[endIt] << endl;
//             startIt++;
//             endIt--;
//         }
//     }
//     return true;
// }

int main()
{
    // aguokepatgbnvfqmgmlcup
    // puculmgmqfvnbgtapekouga
    // string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    // string s = "abca";
    // string s = "eeccccbebaeeabebccceea";
    // string s = "acxcybycxcxa";
    string s = "acxcybycxcxa";

    cout << validPalindrome(s) << endl;
}

// \newcommand{\entry}[5]{% First argument for the leftmost date(s) text, second is for the bold entry heading, third is for the bold right-aligned entry qualifier and the fourth is for the entry description
// 	\parbox[t]{0.175\textwidth}{% 17.5% of the text width of the page
// 		\textcolor{soft}{\small{#1}} % Leftmost entry date(s) text
// 	}%
// 	\parbox[t]{0.825\textwidth}{% 82.5% of the text width of the page
// 		\textcolor{accentbackground}{\textbf{#5}}% Entry heading text
// 		\hfill% Horizontal whitespace
// 		{\footnotesize \textbf{\textcolor{text}{#3}}}\\% Right-aligned entry qualifier text
// 		\vspace{2mm}
// 		\small{\textcolor{text!85}{#2}}
// 		\vspace{0.1cm}
		
// 		\normalsize{#4} % Entry description text
// 	}\\\\\\\\}


// \begin{document}

// %----------------------------------------------------------------------------------------
// %	EXPERIENCE
// %----------------------------------------------------------------------------------------

// \begin{entrylist}
// 	\entry
// 	{03/2020 -- present }
// 		{Primary Function \band Other function}
// 	{Name of the project and/or customer}
// 	{
// 		\vspace{0.3mm}
// 		\begin{minipage}[t]{0.75\textwidth}
// 			\vspace{-\baselineskip}
// 			\itemmarker I achieved something amazing, helping the customer increase their profits by 5000\% over the span of X months. 
// 			\itemmarker  Use active language when describing your efforts and resposabilities. \\
// 			\vspace{-3mm}\\
// 			\itemmarker Try and quantify the things you did. This gives your recruiter a better view of the scope and results. It also demonstrates you know what is important to your customer.\\
//  			\vspace{-3mm}\\
//  			\itemmarker If you talk about a specific technology or methodology that not everyone will be familiar with, include a link to it's website or wiki page. For example: I organized ceremonies to increase developer engagement.\\
//  			\vspace{-3mm}
// 		\end{minipage}

// 		\techlist{Add, the, most, relevant, tools, and, technologies, here}
// 	}
// 	{Self Employed \space\cpipe\space Freelance}

// \end{entrylist}


// \end{document}