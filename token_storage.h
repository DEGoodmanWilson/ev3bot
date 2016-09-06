//
// Created by D.E. Goodman-Wilson on 8/8/16.
//

#pragma once

#include <slack/types.h>

class token_storage
{
public:

    struct token_info
    {
        slack::token access_token;
        slack::token bot_token;
        slack::user_id user_id;
        slack::user_id bot_id;
    };

    token_storage(const std::string &mongo_url) {}

    void set_token(const std::string &team_id, const token_info &token);

    //not super fond of this in/out second parameter.
    bool get_token_for_team(const std::string &team_id, token_info &token);
private:
};
