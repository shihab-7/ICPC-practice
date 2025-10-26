#include<bits/stdc++.h>
using namespace std;

#define shihab ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test int t; cin>>t; while(t--)
#define endl '\n'
#define printv(v) for(auto a:v) cout<<a<<" ";
#define printmp(m) for(auto a:m) cout<<a.first<<" "<<a.second<<endl;
#define ll long long

// ====================
//   ⚡ SQUAD TEMPLATE ⚡
// ====================
//
// smk  → Soumik 💻
// sbs  → Alvi 🍭
// spam → Shihab 🚀

struct LogEntry 
{
    string host;
    string client_ip;
    string id;
    string date_time;
    string date;
    string time;
    string request;
    string http_status;
    string user_agent;
    string session_cookie;
    string pdf_id;
};

struct AbuseSettings 
{
    int agent=0;
    int ip=0;
    int pdf=0;
    int session=0;
    int crawl=0;
};

struct Violation 
{
    string id;
    string abuse_type;
    int value;
    bool operator<(const Violation& other)
    {
        if(id!=other.id) return id<other.id;
        return abuse_type<other.abuse_type;
    }
};

AbuseSettings parse_settings(const string& line) 
{
    AbuseSettings settings;
    stringstream ss(line);
    string token;
    while(getline(ss, token, ',')) 
    {
        int eq = token.find('=');
        if(eq!=-1) {
            string key=token.substr(0, eq);
            string value_str = token.substr(eq + 1);
            key.erase(remove_if(key.begin(), key.end(), ::isspace), key.end());
            value_str.erase(remove_if(value_str.begin(), value_str.end(), ::isspace), value_str.end());
            int value = 0;
            try 
            {
                value = stoi(value_str);
            } 
            catch (...) {}
            if(key=="agent") settings.agent = value;
            else if(key=="ip") settings.ip = value;
            else if(key=="pdf") settings.pdf = value;
            else if(key=="session") settings.session = value;
            else if(key=="crawl") settings.crawl = value;
        }
    }
    return settings;
}

vector<string> split_descriptor(const string& line) 
{
    vector<string> result;
    stringstream ss(line);
    string field;
    while(getline(ss, field, ','))
    {
        while(!field.empty() && field.front()==' ') field.erase(field.begin());
        while(!field.empty() && field.back()==' ') field.pop_back();
        result.push_back(field);
    }
    return result;
}

LogEntry parse_log_line(const string& log_line, const vector<string>& descriptor) 
{
    LogEntry entry;
    string temp_line = log_line;
    int start = 0;
    int end;
    for(int i=0; i<descriptor.size(); ++i) 
    {
        while(start<temp_line.length() && temp_line[start]==' ') start++;
        if(start>=temp_line.length()) break;
        if(temp_line[start]=='"') 
        {
            int next_quote=temp_line.find('"', start + 1);
            end=(next_quote!=-1) ? next_quote + 1 : temp_line.length();
            if(end<temp_line.length() && temp_line[end] == ' ') end++;
        }
        else 
        {
            int next_space = temp_line.find(' ', start);
            end=(next_space!=-1) ? next_space : temp_line.length();
        }
        string token = temp_line.substr(start, end - start);
        start = end;
        if(token.size()>=2 && token.front()=='"' && token.back()=='"') token=token.substr(1, token.size() - 2);
        else if (token.size()>=2 && token.front()=='[' && token.back()==']') 
        {
            token=token.substr(1, token.size() - 2);
            if (descriptor[i]=="Date") {
                int colon_pos=token.find(':');
                if (colon_pos!=-1) {
                    entry.date=token.substr(0, colon_pos);
                    entry.time=token.substr(colon_pos + 1);
                }
            }
        }
        if(descriptor[i]=="Id" && token=="-") token = "";
        if(descriptor[i]=="Host") entry.host = token;
        else if(descriptor[i]=="Client IP") entry.client_ip = token;
        else if(descriptor[i]=="Id") entry.id = token;
        else if(descriptor[i]=="Date") entry.date_time = token;
        else if(descriptor[i]=="Request") entry.request = token;
        else if(descriptor[i]=="HTTP Status") entry.http_status = token;
        else if(descriptor[i]=="User Agent") entry.user_agent = token;
        else if(descriptor[i]=="Session Cookie") entry.session_cookie = token;
    }
    regex pdf_regex("GET /document/([0-9]+)\\.pdf HTTP/1\\.1");
    smatch match;
    if(regex_search(entry.request, match, pdf_regex) && entry.http_status=="200")
    {
        if(match.size()>1) entry.pdf_id=match[1].str();
    }
    return entry;
}

vector<Violation> process_logs(const AbuseSettings& settings, const vector<LogEntry>& log_entries) 
{
    vector<Violation> violations;
    map<string, vector<LogEntry>> logs_by_date;
    for(int i=0; i<log_entries.size(); ++i) 
    {
        LogEntry entry = log_entries[i];
        if(!entry.id.empty()&& entry.http_status=="200")logs_by_date[entry.date].push_back(entry);
    }
    for(auto it=logs_by_date.begin(); it!=logs_by_date.end(); ++it) 
    {
        string date = it->first;
        vector<LogEntry> daily_entries=it->second;
        map<string,set<string>> id_user_agents;
        map<string,set<string>> id_client_ips;
        map<string,int> id_pdf_counts;
        map<string,set<string>> id_session_cookies;
        map<string,vector<LogEntry>> id_pdf_logs;
        for(int j=0; j<daily_entries.size(); ++j) 
        {
            LogEntry entry = daily_entries[j];
            id_user_agents[entry.id].insert(entry.user_agent);
            id_client_ips[entry.id].insert(entry.client_ip);
            if(!entry.session_cookie.empty()) id_session_cookies[entry.id].insert(entry.session_cookie);
            else id_session_cookies[entry.id].insert(entry.id + "_" + entry.client_ip + "_" + date);
            
            if(!entry.pdf_id.empty())
            {
                id_pdf_counts[entry.id]++;
                id_pdf_logs[entry.id].push_back(entry);
            }
        }
        for(auto it2=id_user_agents.begin(); it2!=id_user_agents.end(); ++it2) 
        {
            string id = it2->first;
            int count = it2->second.size();
            if(settings.agent>0 && count>=settings.agent) 
            {
                bool exists = false;
                for(int v=0; v<violations.size(); ++v) 
                {
                    if(violations[v].id==id&&violations[v].abuse_type=="agent") 
                    {
                        exists = true;
                        break;
                    }
                }
                if(!exists) violations.push_back({id, "agent", count});
            }
        }
        for(auto it2=id_client_ips.begin(); it2!=id_client_ips.end(); ++it2) 
        {
            string id = it2->first;
            int count = it2->second.size();
            if(settings.ip>0&& count>=settings.ip)
            {
                bool exists = false;
                for (int v=0; v<violations.size(); ++v)
                {
                    if(violations[v].id==id&&violations[v].abuse_type=="ip")
                    {
                        exists = true;
                        break;
                    }
                }
                if (!exists) violations.push_back({id, "ip", count});
            }
        }
        for(auto it2=id_pdf_counts.begin(); it2!=id_pdf_counts.end(); ++it2) 
        {
            string id=it2->first;
            int count=it2->second;
            if(settings.pdf>0&& count >= settings.pdf) {
                bool exists=false;
                for(int v=0; v<violations.size(); ++v) {
                    if(violations[v].id==id&&violations[v].abuse_type=="pdf") 
                    {
                        exists = true;
                        break;
                    }
                }
                if (!exists) violations.push_back({id, "pdf", count});
            }
        }
        for(auto it2=id_session_cookies.begin(); it2 != id_session_cookies.end(); ++it2) {
            string id=it2->first;
            int count=it2->second.size();
            if(settings.session>0&& count>=settings.session) {
                bool exists=false;
                for(size_t v=0; v<violations.size(); ++v) {
                    if (violations[v].id == id && violations[v].abuse_type == "session") {
                        exists = true;
                        break;
                    }
                }
                if (!exists) violations.push_back({id, "session", count});
            }
        }
        if(settings.crawl>0) {
            for(auto it3=id_pdf_logs.begin(); it3!=id_pdf_logs.end(); ++it3) 
            {
                string id = it3->first;
                vector<LogEntry> pdf_entries=it3->second;
                int max_sequential_pdfs = 0;
                int current_sequential_pdfs = 0;
                string last_pdf_id = "";
                for(int k=0; k<pdf_entries.size(); ++k) {
                    const LogEntry& entry = pdf_entries[k];
                    if(!last_pdf_id.empty())
                    {
                        try
                        {
                            if(stoi(entry.pdf_id)==stoi(last_pdf_id) + 1)current_sequential_pdfs++;
                            else
                            { 
                                if (current_sequential_pdfs > max_sequential_pdfs) max_sequential_pdfs = current_sequential_pdfs;
                                current_sequential_pdfs = 1;
                            }
                        } 
                        catch (...) 
                        {
                            if (current_sequential_pdfs > max_sequential_pdfs) max_sequential_pdfs = current_sequential_pdfs;
                            current_sequential_pdfs = 1;
                        }
                    } 
                    else current_sequential_pdfs=1;
                    last_pdf_id = entry.pdf_id;
                }
                if(current_sequential_pdfs > max_sequential_pdfs) max_sequential_pdfs = current_sequential_pdfs;
                if(max_sequential_pdfs >= settings.crawl) {
                    bool exists = false;
                    for (int v=0; v<violations.size(); ++v) 
                    {
                        if(violations[v].id==id && violations[v].abuse_type=="crawl") 
                        {
                            exists=true;
                            break;
                        }
                    }
                    if(!exists) violations.push_back({id, "crawl", max_sequential_pdfs});
                }
            }
        }
    }
    sort(violations.begin(), violations.end());
    return violations;
}

int main()
{
    shihab
    string settings_line;
    getline(cin, settings_line);
    AbuseSettings settings=parse_settings(settings_line);
    string descriptor_line;
    getline(cin, descriptor_line);
    vector<string> descriptor=split_descriptor(descriptor_line);
    vector<LogEntry> log_entries;
    string log_line;
    while (getline(cin, log_line)) 
    {
        if(log_line.empty()) break;
        log_entries.push_back(parse_log_line(log_line,descriptor));
    }
    vector<Violation> violations = process_logs(settings, log_entries);
    if (violations.empty()) cout<<"N/A"<<endl;
    else 
    {
        for(int i=0; i<violations.size(); i++) 
        {
            cout<<violations[i].id<<" "<<violations[i].abuse_type<<"="<<violations[i].value<<endl;
        }
    }
    return 0;
}