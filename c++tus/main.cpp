#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    string DEFAULT_HOST = "localhost";
    int DEFAULT_PORT = 10036;
    double DEFAULT_GREMLIN_COR = 0.0;
    double DEFAULT_GREMLIN_DRO = 0.0;
    double DEFAULT_GREMLIN_DEL = 0.0;
    int DEFAULT_GREMLIN_DEL_T = 0;
    string DEFAULT_REQUEST_FILE = "{put your files here}";
    string DEFAULT_OUT_FILE = "{put your html files here}";
    string args[] = {};
    map<string, vector<string>> params = parseCommandArgs(args);

    if (tolower(params.get("run").get(0)).equals("server"))
    {
        Server udpServer = initServer(params);
        udpServer.listen();
    }
    else if (tolower(params.get("run").get(0)).equals("client"))
    {
        Client udpClient = initClient(params);
        udpClient.get();
    }
    else
    {
        cout << ("Flags improperly set please use -run client or -run server");
    }
}

Client initClient(map<string, vector<string>> params)
{
    int port = DEFAULT_PORT;
    string host = DEFAULT_HOST;
    double gremlin_cor = DEFAULT_GREMLIN_COR;
    double gremlin_dro = DEFAULT_GREMLIN_DRO;
    double gremlin_del = DEFAULT_GREMLIN_DEL;
    int gremlin_del_t = DEFAULT_GREMLIN_DEL_T;
    string requestFile = DEFAULT_REQUEST_FILE;
    string outFile = DEFAULT_OUT_FILE;
    if (params.findKey("port"))
    {
        port = int(params.get("port").get(0));
    }
    if (params.findKey("host"))
    {
        host = params.get("host").get(0);
    }
    if (params.findKey("gremlin_cor"))
    {
        gremlin_cor = double(params.get("gremlin_cor").get(0));
    }
    if (params.findKey("gremlin_dro"))
    {
        gremlin_dro = double(params.get("gremlin_dro").get(0));
    }
    if (params.findKey("gremlin_del"))
    {
        gremlin_del = double(params.get("gremlin_del").get(0));
    }
    if (params.findKey("gremlin_del_t"))
    {
        gremlin_del_t = int(params.get("gremlin_del_t").get(0));
    }
    if (params.findKey("rfile"))
    {
        requestFile = params.get("rfile").get(0);
    }
    if (params.findKey("ofile"))
    {
        outFile = params.get("ofile").get(0);
    }

    return new Client(port, host, gremlin_cor, gremlin_dro, gremlin_del, gremlin_del_t, requestFile, outFile);
}

Server initServer(map<string, vector<string>> params)
{
    int port = DEFAULT_PORT;
    string host = DEFAULT_HOST;
    if (params.findKey("port"))
    {
        port = int(params.get("port").get(0));
    }
    if (params.containsKey("host"))
    {
        host = params.get("host").get(0);
    }

    return Server(port, host);
}

map<string, vector<string>> parseCommandArgs(string args[])
{
    map<string, vector<string>> out = map<string, vector<string>>();
    vector<string> options;

    for (string a : args)
    {
        if (a.at(0) == '-')
        {
            if (a.length() < 2)
            {
                cout << ("Error at argument " + a);
                return out;
            }
            options = vector<string>();
            out.put(a.substring(1), options);
        }
        else if (options != null)
        {
            options.add(a);
        }
        else
        {
            cout << "Illegal parameter usage. Use '-run server' or '-run client'";
            return out;
        }
    }
    return out;
}
}