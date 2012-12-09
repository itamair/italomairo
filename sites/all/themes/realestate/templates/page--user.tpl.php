<?
//dpm($node);
global $language;
?>
<script>
jQuery(document).ready(function() {
    // Chiamo la mia funzione che svoolge le operazioni che mi ero prefisso.
	spostaIndi();
	jQuery(window).resize(function() {
 spostaIndi();
});
  });

function spostaIndi(){
var win=jQuery(window).width();
	var wNav= jQuery('.flex-control-nav').width();
	var rg=(win/2)+ 465 -wNav;
  jQuery('.flex-control-nav').css('left',rg);
}
</script>
<!-- page-wrapper -->
<div id="page-wrapper" lan="<?print $language->language;?>">
	<!-- container -->
	<div id="container">
		<!-- header -->
		<div id="header">
			<!-- logo sicurezza -->
			<div class="logo">
				<?php if ($logo): ?>
					<a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>">
						<img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
					</a>
				<?php endif; ?>
				
			</div>
			<!-- /logo sicurezza -->
			<!-- claim -->
			<div class="claim">
				<div class="content">
				 <?php if ($page['claim_left']): ?>
					  <?php print render($page['claim_left']); ?>
				  <?php endif; ?>
				
				</div>
			</div>
			<!-- /claim -->
			<!-- claim 2 -->
			<div class="claim2">
				<div class="content">
					<?php if ($page['claim_right']): ?>
					  <?php print render($page['claim_right']); ?>
					<?php endif; ?>
				
				</div>
			</div>
			<!-- /claim 2 -->
			<!-- bandiere -->
			<div class="bandiere">
				<div class="content">
					<?php if ($page['header_right']): ?>
					  <?php print render($page['header_right']); ?>
					<?php endif; ?>
						
				</div>
			</div>
			<!-- /bandiere -->
			<div class="clear"></div>
		</div>
		<!-- /header -->
		<!-- menu principale -->
		<div id="menu1">   
			<div class="sx">
			
				<?php print theme('links__system_main_menu', array('links' => $main_menu, 'attributes' => array('id' => 'main-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Main menu'))); ?>
				<?php
					//print render($page['primary_menu']);
				?>
				
			</div> 
		</div>
		<!-- /menu principale -->
		<!-- slideshow -->
		<div id="bigcontent">
		
		
		<!-- sfondo main 
		<div id="main_bg" style="padding-top:0 !important">-->
			<? if($secondary_menu){?>			
			<div id="menu2"> 
        <?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')), 'heading' => t('Secondary menu'))); ?>
			
			</div>
			<? } ?>
			<div id="main_bg" <?
			if (!$page['content_header'])
			{?>style="padding-top:25px">
			<? }?>
			<!-- sottomenu -->
		
			<!-- /sottomenu -->

		<?php if ($page['content_header']): ?>
			  <?php print render($page['content_header']); ?>
		<?php endif; ?>
				
			<!-- box contenuti pagina generica -->
				<div id="main_bg"  >
				<div class="box03" >
									<div class="containermsgwebformxx">
					<?php print $messages; ?>
					
							</div>
				<div class="top2"></div>
				<div class="largobg">
					<div class="wrapper3">
					<div id="main-wrapper">
						<div id="main" class="clearfix">
							<div id="content" class="column">
								<div class="section">
									<a id="main-content"></a>
									<?php print render($title_suffix); ?>
									<?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
									<?php print render($page['help']); ?>
									<?php print render($tabs2); ?>
									<?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
									<div class="spaziotitolo webforms-results"><? print t('Username').': '.$title;?></div>
									<div class="clearfix">
										<?php print render($page['content']); ?>
									</div>
									<!--/CONTENUTO GENERALE-->
									<?php print $feed_icons; ?>
									<div class="clear"></div> 
								</div>
							</div> <!-- /.section, /#content -->
						</div>
					</div>					
					</div>					
				</div>
				<div class="bottom"></div>  
			</div>
				
			<!-- /box contenuti pagina generica -->
		</div>
		<!-- fine sfondo main -->

		
		
		<!-- /slideshow -->
		<!-- main con i 3 box -->
		
		<div id="hp_main">
			<?php if ($page['content_bottom']): ?>
			  <?php print render($page['content_bottom']); ?>
			<?php endif; ?>
		
			<? if ($is_front) {?>
			<!-- box ultime notizie -->
			<div class="box01">
				<div class="content">
					<?php if ($page['content_bottom_left']): ?>
						<?php print render($page['content_bottom_left']); ?>
					<?php endif; ?>
					
				</div>
			</div>   
			<!-- /box ultime notizie -->
			<!-- box adv -->
			<div class="box02">
				<div class="content">
					<?php if ($page['content_bottom_center']): ?>
						<?php print render($page['content_bottom_center']); ?>
					<?php endif; ?>
					
				</div>
			</div>   
			<!-- /box adv -->
			<!-- box eventi -->
			<div class="box01" style="margin-right:0">
				<div class="content">
					<?php if ($page['content_bottom_right']): ?>
						<?php print render($page['content_bottom_right']); ?>
					<?php endif; ?>
					
				</div>
				
			</div>   <? } ?>
			<!-- /box ultime notizie -->
			<div class="clear"></div>
		</div>
		<!-- /main con i 3 box -->
		<!-- footer -->
		</div>
		<div id="footer">
			<div class="contentgeneral">
				<div class="testi">
					<div class="legale">
						<?php if ($page['footer_left_up']): ?>
							<?php print render($page['footer_left_up']); ?>
						<?php endif; ?>
						<!--
						-->
					</div>
					<div class="copy">
						<?php if ($page['footer_left_bottom']): ?>
							<?php print render($page['footer_left_bottom']); ?>
						<?php endif; ?>
						<!---->
					</div>
				</div>
				<div class="logo">
					<?php if ($page['footer_right']): ?>
						<?php print render($page['footer_right']); ?>
					<?php endif; ?>
					<!---->
				</div>
				<div class="clear"></div>

			</div>
		</div>
		<!-- /footer -->
	</div>
	<!-- /container -->
</div>
<!-- /page wrapper -->
