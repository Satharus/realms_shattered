
#include "game_state.hpp"

void GameState::game_state_player_hub()
{
   m_console.print_box( 0, 0, m_console.width_get(), m_console.height_get(), '+' );
   m_console.print( m_game_title, ( ( m_console.width_get() / 2 ) - ( m_game_title.length() / 2 ) ), 1 );

   m_user_interface.player_stats_brief_display( m_console, m_language, m_game_data );
   m_user_interface.command_prompt_display( m_console, m_language );
   CommandTag command_tag( m_user_input.player_command_get( m_language ) );
      
   switch( command_tag ) {
      case CommandTag::COMMAND_INVALID:
         break;
      case CommandTag::COMMAND_HELP:
         m_user_interface.help_list_display( m_console, m_language );
         break;
      case CommandTag::COMMAND_QUIT:
         m_game_data.game_terminate();
         break;
   }
      
   m_user_interface.pause_and_display_message( m_console );
   m_console.clear();
}
