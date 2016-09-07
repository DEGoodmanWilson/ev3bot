//
// Created by D.E. Goodman-Wilson on 8/8/16.
//

#include "token_storage.h"
#include <iostream>
#include <sstream>


token_storage::token_storage(const std::string &db_name) : db_{db_name.c_str()}
{
    db_.execute("CREATE TABLE tokens(\n"
                       "   team_id       TEXT PRIMARY KEY    NOT NULL,\n"
                       "   user_id       TEXT                NOT NULL,\n"
                       "   bot_id        TEXT                NOT NULL,\n"
                       "   access_token  TEXT                NOT NULL,\n"
                       "   bot_token     TEXT                NOT NULL\n"
                       ");");

}

void token_storage::set_token(const std::string &team_id, const token_info &token)
{
    sqlite3pp::command cmd(db_, "INSERT INTO tokens (team_id, user_id, bot_id, access_token, bot_token) VALUES (?, ?, ?, ?, ?)");
    cmd.binder() << team_id.c_str() << token.user_id.c_str() << token.bot_id.c_str() << token.access_token.c_str() << token.bot_token.c_str();
    cmd.execute();
}

bool token_storage::get_token_for_team(const std::string &team_id, token_info &token)
{
    std::stringstream strm;
    strm << "SELECT user_id, bot_id, access_token, bot_token FROM tokens WHERE team_id='" << team_id << "' LIMIT 1";
    sqlite3pp::query qry(db_, strm.str().c_str());

    for (auto v : qry)
    {
        v.getter() >> token.user_id >> token.bot_id >> token.access_token >> token.bot_token;
        return true;
    }

    return false;
}