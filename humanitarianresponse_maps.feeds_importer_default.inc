<?php
/**
 * @file
 * humanitarianresponse_maps.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function humanitarianresponse_maps_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'csv_visuals';
  $feeds_importer->config = array(
    'name' => 'CSV Visuals',
    'description' => 'Import visuals from a CSV file',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'csv',
        'direct' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'content_type' => 'map',
        'expire' => '-1',
        'author' => 0,
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'Title',
            'target' => 'title_field',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Type',
            'target' => 'field_map_type',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'File',
            'target' => 'field_map_file',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Language',
            'target' => 'field_file_languages',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Publication Date',
            'target' => 'field_publication_date:start',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Source',
            'target' => 'field_organizations',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Location',
            'target' => 'field_locations',
            'unique' => FALSE,
          ),
          8 => array(
            'source' => 'Cluster',
            'target' => 'field_clusters',
            'unique' => FALSE,
          ),
          9 => array(
            'source' => 'Themes',
            'target' => 'field_themes',
            'unique' => FALSE,
          ),
          10 => array(
            'source' => 'Coordination Hub',
            'target' => 'field_coordination_hubs',
            'unique' => FALSE,
          ),
          11 => array(
            'source' => 'Emergencies',
            'target' => 'field_emergencies',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['csv_visuals'] = $feeds_importer;

  return $export;
}