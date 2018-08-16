<?xml version='1.0'?>
<xsl:stylesheet
	version="1.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="branches">
		<html>
			<head>
				<title> Test Results </title>
			</head>

			<body bgcolor="#e0e0f0">
				<div align="center">
			        <h3>
            	        <b> ROS Test Results </b>
            		</h3>
            	</div>
		        <table cols="4" width="90%" align="center">
			        <tr>
				        <td width="25%" colspan="2"> 
                            Branch
                        </td>
				        <td width="37.5%" colspan="3"> 
                            Failed Tests
                        </td>
				        <td width="37.5%" colspan="3">
                            All Tests
                        </td>
        			</tr>
		        	<xsl:apply-templates/>
        		</table>
		        <p/>
        		<hr align="center" width="90%" color="maroon" />
			</body>
		</html>
	</xsl:template>

	<xsl:template match="branch">
        <xsl:param name="shortName" select="@shortName"/>
		<tr bgcolor="#ffffc0">
			<td width="25%" colspan="2">
				<xsl:value-of select="@shortName"/>
			</td>
			<td width="12.5%">
                <a href="{$shortName}/unit_tests_failed.html">
                    Unit
                </a>
			</td>
            <td width="12.5%">
                <a href="{$shortName}/integration_tests_failed.html">
                    Integration
                </a>
			</td>
            <td width="12.5%">
                <a href="{$shortName}/acceptance_tests_failed.html">
                    Acceptance
                </a>
			</td>
            <td width="12.5%">
                <a href="{$shortName}/unit_tests_all.html">
                    Unit
                </a>
			</td>
            <td width="12.5%">
                <a href="{$shortName}/integration_tests_all.html">
                    Integration
                </a>
			</td>
            <td width="12.5%">
                <a href="{$shortName}/acceptance_tests_all.html">
                    Acceptance
                </a>
			</td>
		</tr>
	</xsl:template>
</xsl:stylesheet>
