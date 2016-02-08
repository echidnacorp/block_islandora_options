(function ($) {

/**
 * Provide the summary information for the islandora_block_options settings
 * vertical tab.
 */
Drupal.behaviors.blockIslandoraOptionsVisibilitySettingsSummary = {
  attach: function (context) {

    $('fieldset#edit-islandora-cmodels', context).drupalSetSummary(function (context) {
      console.log($('fieldset#edit-islandora-cmodels input[type="checkbox"]:checked').length);
      if ($('fieldset#edit-islandora-cmodels input[type="checkbox"]:checked').length) {
        return $('fieldset#edit-islandora-cmodels input[type="checkbox"]:checked ~ label.option').map(function () {
          return $(this).text().trim();
        }).get().join(", ");
      } else {
        return Drupal.t('Not restricted');
      }
      return $('checkbox:checked', context).text();
    });

  }
};

})(jQuery);
