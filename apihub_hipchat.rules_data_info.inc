<?php
/**
 * @file
 * apihub_hipchat.rules_data_info.inc
 */

/**
 * Implements hook_rules_data_info_defaults().
 */
function apihub_hipchat_rules_data_info_defaults() {
  $export = array();

  $data_type = new stdClass();
  $data_type->disabled = FALSE; /* Edit this to true to make a default data_type disabled initially */
  $data_type->api_version = 1;
  $data_type->name = 'hipchat_file';
  $data_type->category = 'HipChat';
  $data_type->admin_title = 'File';
  $data_type->admin_description = '';
  $data_type->data = array(
    'property info' => array(
      'name' => array(
        'label' => 'Name',
        'id' => 'name',
        'type' => 'text',
      ),
      'size' => array(
        'label' => 'Size',
        'id' => 'size',
        'type' => 'integer',
      ),
      'url' => array(
        'label' => 'URL',
        'id' => 'url',
        'type' => 'uri',
      ),
    ),
  );
  $export['hipchat_file'] = $data_type;

  $data_type = new stdClass();
  $data_type->disabled = FALSE; /* Edit this to true to make a default data_type disabled initially */
  $data_type->api_version = 1;
  $data_type->name = 'hipchat_mesage';
  $data_type->category = 'HipChat';
  $data_type->admin_title = 'Mesage';
  $data_type->admin_description = '';
  $data_type->data = array(
    'property info' => array(
      'date' => array(
        'label' => 'Date message was sent',
        'id' => 'date',
        'type' => 'date',
      ),
      'from' => array(
        'label' => 'Name and user_id of sender',
        'id' => 'from',
        'type' => 'hipchat_user',
      ),
      'message' => array(
        'label' => 'Message body',
        'id' => 'message',
        'type' => 'text',
      ),
      'file' => array(
        'label' => 'File',
        'id' => 'file',
        'type' => 'hipchat_file',
      ),
    ),
  );
  $export['hipchat_mesage'] = $data_type;

  $data_type = new stdClass();
  $data_type->disabled = FALSE; /* Edit this to true to make a default data_type disabled initially */
  $data_type->api_version = 1;
  $data_type->name = 'hipchat_room';
  $data_type->category = 'HipChat';
  $data_type->admin_title = 'Room';
  $data_type->admin_description = '';
  $data_type->data = array(
    'property info' => array(
      'room_id' => array(
        'label' => 'ID of the room',
        'id' => 'room_id',
        'type' => 'integer',
      ),
      'name' => array(
        'label' => 'Name of the room',
        'id' => 'name',
        'type' => 'text',
      ),
      'topic' => array(
        'label' => 'Current topic',
        'id' => 'topic',
        'type' => 'text',
      ),
      'last_active' => array(
        'label' => 'Time of last activity',
        'id' => 'last_active',
        'type' => 'date',
      ),
      'created' => array(
        'label' => 'Time the room was created',
        'id' => 'created',
        'type' => 'date',
      ),
      'owner_user_id' => array(
        'label' => 'User ID of the room owner',
        'id' => 'owner_user_id',
        'type' => 'integer',
      ),
      'is_archived' => array(
        'label' => 'Whether room is archived',
        'id' => 'is_archived',
        'type' => 'boolean',
      ),
      'is_private' => array(
        'label' => 'Whether room is private',
        'id' => 'is_private',
        'type' => 'boolean',
      ),
      'guest_access_url' => array(
        'label' => 'URL for guess access',
        'id' => 'guest_access_url',
        'type' => 'uri',
      ),
      'xmpp_jid' => array(
        'label' => 'XMPP/Jabber ID of the room',
        'id' => 'xmpp_jid',
        'type' => 'text',
      ),
    ),
  );
  $export['hipchat_room'] = $data_type;

  $data_type = new stdClass();
  $data_type->disabled = FALSE; /* Edit this to true to make a default data_type disabled initially */
  $data_type->api_version = 1;
  $data_type->name = 'hipchat_user';
  $data_type->category = 'HipChat';
  $data_type->admin_title = 'User';
  $data_type->admin_description = '';
  $data_type->data = array(
    'property info' => array(
      'user_id' => array(
        'label' => 'User\'s ID',
        'id' => 'user_id',
        'type' => 'text',
      ),
      'email' => array(
        'label' => 'User\'s email',
        'id' => 'email',
        'type' => 'text',
      ),
      'is_deleted' => array(
        'label' => 'Whether the account is deleted',
        'id' => 'is_deleted',
        'type' => 'boolean',
      ),
      'is_group_admin' => array(
        'label' => 'Whether the user is an admin',
        'id' => 'is_group_admin',
        'type' => 'boolean',
      ),
      'name' => array(
        'label' => 'User\'s full name',
        'id' => 'name',
        'type' => 'text',
      ),
      'mention_name' => array(
        'label' => 'User\'s @mention name',
        'id' => 'mention_name',
        'type' => 'text',
      ),
      'photo_url' => array(
        'label' => 'URL to user\'s photo',
        'id' => 'photo_url',
        'type' => 'uri',
      ),
      'last_active' => array(
        'label' => 'Time the account was last used',
        'id' => 'last_active',
        'type' => 'date',
      ),
      'created' => array(
        'label' => 'Time the user was created',
        'id' => 'created',
        'type' => 'date',
      ),
      'status' => array(
        'label' => 'User\'s current status',
        'id' => 'status',
        'type' => 'text',
      ),
      'status_message' => array(
        'label' => 'User\'s current status message',
        'id' => 'status_message',
        'type' => 'text',
      ),
      'timezone' => array(
        'label' => 'User\'s timezone',
        'id' => 'timezone',
        'type' => 'text',
      ),
      'title' => array(
        'label' => 'User\'s title',
        'id' => 'title',
        'type' => 'text',
      ),
    ),
  );
  $export['hipchat_user'] = $data_type;

  return $export;
}
