<?php

/**
 * Implements hook_features_export_options().
 */
function block_islandora_options_config_features_export_options() {
  $field_types = array(
    'all_options' => t('All Islandora Block Options.'),
  );
  return $field_types;
}

/**
 * Implements hook_features_export().
 */
function block_islandora_options_config_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['block_islandora_options'] = 'block_islandora_options';

  foreach ($data as $component) {
    $export['features']['block_islandora_options_config'][$component] = $component;
  }
}

/**
 * Implements hook_features_export_render().
 */
function block_islandora_options_config_features_export_render($module_name, $data, $export = NULL) {
  $code = array();
  if (in_array('all_options', $data)) {
    $code = block_islandora_options_all_options();
  }
  $code = '  return ' . features_var_export($code) . ';';
  return array('block_islandora_options_config_features_default_settings' => $code);
}

/**
 * Implements hook_features_revert().
 */
function block_islandora_options_config_features_revert($module) {
  block_islandora_options_config_features_rebuild($module);
}

/**
 * Implements hook_features_rebuild().
 */
function block_islandora_options_config_features_rebuild($module) {
  $items = module_invoke($module, 'block_islandora_options_config_features_default_settings');
  if (!empty($items)) {
    db_delete('block_islandora_options')->execute();
  }

  foreach ($items as $item) {
    $opt = new stdClass;
    $opt->module = $item['module'];
    $opt->delta = $item['delta'];
    $opt->cmodel = $item['cmodel'];
    block_islandora_options_save_option($opt);
  }
}