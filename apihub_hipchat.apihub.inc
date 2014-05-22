<?php
/**
 * @file
 * apihub_hipchat.apihub.inc
 */

/**
 * Implements hook_apihub_apis().
 */
function apihub_hipchat_apihub_apis() {
  $export = array();

  $api = new stdClass();
  $api->disabled = FALSE; /* Edit this to true to make a default api disabled initially */
  $api->api_version = 1;
  $api->name = 'hipchat';
  $api->admin_title = 'HipChat';
  $api->description = '';
  $api->url = 'http://api.hipchat.com/v1';
  $export['hipchat'] = $api;

  return $export;
}

/**
 * Implements hook_apihub_resources().
 */
function apihub_hipchat_apihub_resources() {
  $export = array();

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = '0363fc788f17cca394ce96b8d4cf317b';
  $resource->admin_title = 'Users - List';
  $resource->description = 'List all users in the group.';
  $resource->method = 'GET';
  $resource->path = '/users/list';
  $resource->parameters = array(
    0 => array(
      'name' => 'Include deleted',
      'id' => 'include_deleted',
      'type' => 'boolean',
      'options' => '',
      'required' => 0,
      'description' => 'Include deleted users in response.',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Users',
        'id' => 'users',
        'type' => 'list<hipchat_user>',
      ),
    ),
  );
  $export['0363fc788f17cca394ce96b8d4cf317b'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = '2338f18a23bd450e3ecdd4064581266c';
  $resource->admin_title = 'Rooms - History';
  $resource->description = 'Fetch chat history for this room.';
  $resource->method = 'GET';
  $resource->path = '/rooms/history';
  $resource->parameters = array(
    0 => array(
      'name' => 'Room ID',
      'id' => 'room_id',
      'type' => 'decimal',
      'options' => '',
      'required' => 1,
      'description' => 'ID of the room.',
    ),
    1 => array(
      'name' => 'Date',
      'id' => 'date',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'Either the date to fetch history for in YYYY-MM-DD format, or "recent" to fetch the latest 75 messages.',
    ),
    2 => array(
      'name' => 'Timezone',
      'id' => 'timezone',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'Your timezone. Must be a supported timezone - https://www.hipchat.com/docs/api/timezones. (default: UTC)',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Messages',
        'id' => 'messages',
        'type' => 'list<hipchat_mesage>',
      ),
    ),
  );
  $export['2338f18a23bd450e3ecdd4064581266c'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = '2fd7e066c0b59803b8abcce72cae6688';
  $resource->admin_title = 'Rooms - Message';
  $resource->description = 'Send a message to a room.';
  $resource->method = 'POST';
  $resource->path = '/rooms/message';
  $resource->parameters = array(
    0 => array(
      'name' => 'Room ID',
      'id' => 'room_id',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'ID or name of the room.',
    ),
    1 => array(
      'name' => 'From',
      'id' => 'from',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'Name the message will appear be sent from. Must be less than 15 characters long. May contain letters, numbers, -, _, and spaces.',
    ),
    2 => array(
      'name' => 'Message',
      'id' => 'message',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'The message body. 10,000 characters max.',
    ),
    3 => array(
      'name' => 'Message format',
      'id' => 'message_format',
      'type' => 'text',
      'options' => 'html|HTML
text|Text',
      'required' => 0,
      'description' => 'Determines how the message is treated by our server and rendered inside HipChat applications. (default: html)',
    ),
    4 => array(
      'name' => 'Notify',
      'id' => 'notify',
      'type' => 'boolean',
      'options' => '',
      'required' => 0,
      'description' => 'Whether or not this message should trigger a notification for people in the room (change the tab color, play a sound, etc). Each recipient\'s notification preferences are taken into account.',
    ),
    5 => array(
      'name' => 'Color',
      'id' => 'color',
      'type' => 'text',
      'options' => 'yellow|Yellow
red|Red
green|Green
purple|Purple
gray|Gray
random|Random',
      'required' => 0,
      'description' => 'Background color for message. One of "yellow", "red", "green", "purple", "gray", or "random". (default: yellow)',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Status',
        'id' => 'status',
        'type' => 'text',
      ),
    ),
  );
  $export['2fd7e066c0b59803b8abcce72cae6688'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = '318a7ccbe6cf981bec51c4feb4089729';
  $resource->admin_title = 'Users - Undelete';
  $resource->description = 'Undelete a user. They will be sent an email requiring them to click a link to reactivate the account.';
  $resource->method = 'POST';
  $resource->path = '/users/undelete';
  $resource->parameters = array(
    0 => array(
      'name' => 'User ID',
      'id' => 'user_id',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'ID or email address of the user.',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Undeleted',
        'id' => 'undeleted',
        'type' => 'boolean',
      ),
    ),
  );
  $export['318a7ccbe6cf981bec51c4feb4089729'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = '3385d80047022f52f598d8851b81b94a';
  $resource->admin_title = 'Rooms - Show';
  $resource->description = 'Get room details.';
  $resource->method = 'GET';
  $resource->path = '/rooms/show';
  $resource->parameters = array(
    0 => array(
      'name' => 'Room ID',
      'id' => 'room_id',
      'type' => 'decimal',
      'options' => '',
      'required' => 1,
      'description' => 'ID of the room.',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Room',
        'id' => 'room',
        'type' => 'hipchat_room',
      ),
    ),
  );
  $export['3385d80047022f52f598d8851b81b94a'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = '5c87befcbc80f44db7373b23d94fa71b';
  $resource->admin_title = 'Users - Create';
  $resource->description = 'Create a new user in your group.';
  $resource->method = 'POST';
  $resource->path = '/users/create';
  $resource->parameters = array(
    0 => array(
      'name' => 'Email',
      'id' => 'email',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'User\'s email.',
    ),
    1 => array(
      'name' => 'Name',
      'id' => 'name',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'User\'s full name.',
    ),
    2 => array(
      'name' => 'Mention name',
      'id' => 'mention_name',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s @mention name.',
    ),
    3 => array(
      'name' => 'Title',
      'id' => 'title',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s title.',
    ),
    4 => array(
      'name' => 'Is group admin',
      'id' => 'is_group_admin',
      'type' => 'boolean',
      'options' => '',
      'required' => 0,
      'description' => '',
    ),
    5 => array(
      'name' => 'Password',
      'id' => 'password',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s password. If not provided, a randomly generated password will be returned.',
    ),
    6 => array(
      'name' => 'Timezone',
      'id' => 'timezone',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s timezone. Must be a supported timezone - https://www.hipchat.com/docs/api/timezones. (default: UTC)',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'User',
        'id' => 'user',
        'type' => 'hipchat_user',
      ),
    ),
  );
  $export['5c87befcbc80f44db7373b23d94fa71b'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = '64d68603b6d4e281b24aac55f55de4a7';
  $resource->admin_title = 'Users - Update';
  $resource->description = 'Update a user.';
  $resource->method = 'POST';
  $resource->path = '/users/update';
  $resource->parameters = array(
    0 => array(
      'name' => 'User ID',
      'id' => 'user_id',
      'type' => 'decimal',
      'options' => '',
      'required' => 1,
      'description' => 'User\'s ID.',
    ),
    1 => array(
      'name' => 'Email',
      'id' => 'email',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s email.',
    ),
    2 => array(
      'name' => 'Name',
      'id' => 'name',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s full name.',
    ),
    3 => array(
      'name' => 'Mention name',
      'id' => 'mention_name',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s @mention name.',
    ),
    4 => array(
      'name' => 'Title',
      'id' => 'title',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s title.',
    ),
    5 => array(
      'name' => 'Is group admin',
      'id' => 'is_group_admin',
      'type' => 'boolean',
      'options' => '',
      'required' => 0,
      'description' => 'Whether or not this user is an admin.',
    ),
    6 => array(
      'name' => 'Password',
      'id' => 'password',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s password.',
    ),
    7 => array(
      'name' => 'Timezone',
      'id' => 'timezone',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'User\'s timezone. Must be a supported timezone - https://www.hipchat.com/docs/api/timezones.',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'User',
        'id' => 'user',
        'type' => 'hipchat_user',
      ),
    ),
  );
  $export['64d68603b6d4e281b24aac55f55de4a7'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = '68d68bf19c2b4445b49b3f21a9c47eb6';
  $resource->admin_title = 'Rooms - Topic';
  $resource->description = 'Set a room\'s topic. Useful for displaying statistics, important links, server status, you name it!';
  $resource->method = 'POST';
  $resource->path = '/rooms/topic';
  $resource->parameters = array(
    0 => array(
      'name' => 'Room ID',
      'id' => 'room_id',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'ID or name of the room.',
    ),
    1 => array(
      'name' => 'Topic',
      'id' => 'topic',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'The topic body. 250 characters max.',
    ),
    2 => array(
      'name' => 'From',
      'id' => 'from',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'Name of the service changing the topic. (default: API)',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Status',
        'id' => 'status',
        'type' => 'text',
      ),
    ),
  );
  $export['68d68bf19c2b4445b49b3f21a9c47eb6'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = '6991c18cba0951c9e58d78ab71fb51aa';
  $resource->admin_title = 'Rooms - Delete';
  $resource->description = 'Deletes a room and kicks the current participants.';
  $resource->method = 'POST';
  $resource->path = '/rooms/delete';
  $resource->parameters = array(
    0 => array(
      'name' => 'Room ID',
      'id' => 'room_id',
      'type' => 'decimal',
      'options' => '',
      'required' => 1,
      'description' => '',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Deleted',
        'id' => 'deleted',
        'type' => 'boolean',
      ),
    ),
  );
  $export['6991c18cba0951c9e58d78ab71fb51aa'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = 'abb5d9a96739a9b89feb99bb72421bc2';
  $resource->admin_title = 'Rooms - List';
  $resource->description = 'List rooms for this group.';
  $resource->method = 'GET';
  $resource->path = '/rooms/list';
  $resource->parameters = array();
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Rooms',
        'id' => 'rooms',
        'type' => 'list<hipchat_room>',
      ),
    ),
  );
  $export['abb5d9a96739a9b89feb99bb72421bc2'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = 'c08327f58a0494279a25a8a519ac6aea';
  $resource->admin_title = 'Rooms - Create';
  $resource->description = 'Creates a new room.';
  $resource->method = 'POST';
  $resource->path = '/rooms/create';
  $resource->parameters = array(
    0 => array(
      'name' => 'Name',
      'id' => 'name',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'Name of the room.',
    ),
    1 => array(
      'name' => 'Owner user ID',
      'id' => 'owner_user_id',
      'type' => 'decimal',
      'options' => '',
      'required' => 1,
      'description' => 'User ID of the room\'s owner.',
    ),
    2 => array(
      'name' => 'Privacy',
      'id' => 'privacy',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'Privacy (default: public)',
    ),
    3 => array(
      'name' => 'Topic',
      'id' => 'topic',
      'type' => 'text',
      'options' => '',
      'required' => 0,
      'description' => 'Initial room topic',
    ),
    4 => array(
      'name' => 'Guest access',
      'id' => 'guest_access',
      'type' => 'boolean',
      'options' => '',
      'required' => 0,
      'description' => 'Whether or not to enable guest access for this room.',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Room',
        'id' => 'room',
        'type' => 'hipchat_room',
      ),
    ),
  );
  $export['c08327f58a0494279a25a8a519ac6aea'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = 'ea9ed20eefccef7e3202250c8ab79d84';
  $resource->admin_title = 'Users - Show';
  $resource->description = 'Get a user\'s details.';
  $resource->method = 'GET';
  $resource->path = '/users/show';
  $resource->parameters = array(
    0 => array(
      'name' => 'User ID',
      'id' => 'user_id',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'ID or email address of the user.',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'User',
        'id' => 'user',
        'type' => 'hipchat_user',
      ),
    ),
  );
  $export['ea9ed20eefccef7e3202250c8ab79d84'] = $resource;

  $resource = new stdClass();
  $resource->disabled = FALSE; /* Edit this to true to make a default resource disabled initially */
  $resource->api_version = 1;
  $resource->api = 'hipchat';
  $resource->name = 'eb1734a01d90f83552c312cb96954868';
  $resource->admin_title = 'Users - Delete';
  $resource->description = 'Delete a user.';
  $resource->method = 'POST';
  $resource->path = '/users/delete';
  $resource->parameters = array(
    0 => array(
      'name' => 'User ID',
      'id' => 'user_id',
      'type' => 'text',
      'options' => '',
      'required' => 1,
      'description' => 'ID or email address of the user.',
    ),
  );
  $resource->settings = array(
    'rules' => array(
      'provides' => array(
        'name' => 'Deleted',
        'id' => 'deleted',
        'type' => 'boolean',
      ),
    ),
  );
  $export['eb1734a01d90f83552c312cb96954868'] = $resource;

  return $export;
}
