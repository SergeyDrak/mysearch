<?php

/**
 * @file
 * Implementation of the search form in the block module.
 */


/**
 * Implements hook_block_info().
 */
function mysearch_block_info() {
  $blocks['mysearch_block'] = array(
    'info' => t('Simple search form'),
    'cache' => DRUPAL_CACHE_GLOBAL,
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function mysearch_block_view($delta = '') {
  $block = array();
  switch ($delta) {
    case 'mysearch_block':
      $block['subject'] = t('Simple search form');
      $block['content'] = drupal_get_form('mysearch_form');
      break;
  }
  return $block;
}

/**
 * Implements hook_block_configure().
 */
function mysearch_block_configure($delta = '') {
  $form = array();
  if ($delta == 'mysearch_block') {
    $form['block_coll_items'] = array(
      '#type' => 'textfield',
      '#title' => t('Items for display in search result'),
      '#default_value' => variable_get('mysearch_coll'),
    );
  }
  return $form;
}

/**
 * Implements hook_block_save().
 */
function mysearch_block_save($delta = '', $edit = array()) {
  if ($delta == 'mysearch_block') {
    variable_set('mysearch_coll', $edit['block_coll_items']);
  }
}

/**
 * Build simple search form.
 */
function mysearch_form($form, $form_state) {
  $form = array();
  $form['term'] = array(
    '#type' => 'textfield',
    '#size' => 100,
    '#attributes' => array('placeholder' => t('Enter text to search for.'))
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
  );
  return $form;
}


/**
 * Validate function for mysearch_form.
 */
function mysearch_form_validate($form, &$form_state) {
  $form_state['values']['term'] = strip_tags($form_state['values']['term']);
  if (empty($form_state['values']['term'])) {
    form_set_error('term', t('The field can not be empty.'));
  }
}

/**
 * Submit function for mysearch_form.
 */
function mysearch_form_submit($form, &$form_state) {
  $path = $form_state['values']['term'].'/'.variable_get('mysearch_coll');
  drupal_goto("/mysearch/$path");
}