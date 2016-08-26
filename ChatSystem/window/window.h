#pragma once

#include <iostream>
#include <ncurses.h>
#include <string>
#include <string.h>
#include <comm.h>
#include <pthread.h>

class chat_window{
	public:
		chat_window();
		void init();
		WINDOW* create_win(const int &hei, const int &wth, const int &y, const int &x);
		void win_refresh(WINDOW *_win);
		void put_str_to_win(WINDOW *_win, int y, int x, const std::string &_str);
		void get_str_from_win(WINDOW *_win, std::string &_out);
		void clear_win_line(WINDOW *_win, int begin, int num);
		~chat_window();

		void draw_header();
		void draw_output();
		void draw_friends_list();
		void draw_input();

		WINDOW *get_header()
		{ return this->header; }

		WINDOW *get_output()
		{ return this->output; }

		WINDOW *get_friends_list()
		{ return this->friends_list; }

		WINDOW *get_input()
		{ return this->input; }
	private:
		pthread_mutex_t lock;
		WINDOW *header;
		WINDOW *output;
		WINDOW *friends_list;
		WINDOW *input;
};
