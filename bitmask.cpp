#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <QApplication>
#include <QWebView>

using namespace std;

static string expand_env_vars(string s) {
    if(s.find("${") == string::npos) return s;

    string pre  = s.substr(0, s.find("${"));
    string post = s.substr(s.find("${" ) + 2);

    if(post.find('}') == string::npos) return s;

    string variable = post.substr(0, post.find( '}' ));
    string value    = "";

    post = post.substr(post.find( '}' ) + 1);

    if(getenv(variable.c_str()) != NULL) value = string(getenv(variable.c_str()));

    return expand_env_vars(pre + value + post);
}


int main(int argc, char *argv[])
{
    stringstream url;
    string conf;
    string token;
    string path;

    conf = "${HOME}/.config/leap/authtoken";
    path = expand_env_vars(conf);
    ifstream tokenf (path);
    getline(tokenf, token);
    tokenf.close();

    url << "http://localhost:7070/#" << token;
    QString qurl = QString::fromStdString(url.str());

    QApplication app(argc, argv);
    QWebView view;
    view.show();
    view.load(QUrl(qurl));

    return app.exec();
}
