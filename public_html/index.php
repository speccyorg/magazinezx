<?php
//Section mapping
$pages = array('index', 'editorial', 'analisis', 'zona-pc', 'zona-www', 'hardware', 'emulacion', 'zona-remake', 'basic', 'la-historia-del-spectrum', 'panorama', 'input', 'al-descubierto', 'ensamblador', 'z88dk', 'opinion', 'el-aventurero', 'rem', 'tira-comica', '128k-mode', 'computone');
//Get parameters
$revista = $_GET['revista'];
$seccion = $_GET['seccion'];
if(!isset($seccion))
{
	$seccion = 0;
}
//Check parameters
if (is_numeric($revista) && $revista >= 1 && $revista <= 17)
{
	if(is_numeric($seccion) && $seccion >= 0 && $seccion <= 20)
	{
		if ($revista < 10)
		{
			$revista = '0' . $revista;
		}
		$url = 'http://www.speccy.org/magazinezx/' . $revista . '/' . $pages[$seccion] . '.html';
		header('HTTP/1.1 301 Moved Permanently');
		header('Location: ' . $url);
		die();
	}
}
header('HTTP/1.1 301 Moved Permanently');
header('Location: http://www.speccy.org/magazinezx/index.html');
?>
