<?php
/**
 * @file
 * apihub_hipchat.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function apihub_hipchat_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apihub" && $api == "apihub") {
    return array("version" => "1");
  }
}
